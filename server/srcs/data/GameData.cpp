//
// GameData.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Wed Oct 22 13:29:09 2014 
// Last Update Tue Nov 18 10:01:10 2014 
//

#include "abstractions/allocs.hh"
#include "data/GameData.hh"
#include "debug/LogManager.hh"

#include <cstring>

GameData::GameData(const Configs& configs) :
  m_teamsNumber(configs.getTeams().getNumber()),
  m_started(false)
{
  unsigned int	i;

  LogManagerSingleton::access()->intern->print("Initialisating game data...");

  m_teams.resize(configs.getTeams().getNumber());
  for (i = 0; i < m_teamsNumber; ++i)
    m_teams << Team(configs.getTeams().getName(i));
}

GameData::~GameData()
{
  unsigned int	i;

  for (i = 0; i < m_teamsNumber; ++i)
    m_teams[i].destroy();
}


const Team*
GameData::getTeam(const char* name) const
{
  const Team*	team;
  unsigned int	i;

  team = NULL;

  for (i = 0; team == NULL && i < m_teamsNumber; ++i)
    if (!strcmp(m_teams[i].getName(), name))
      team = &m_teams[i];

  return (team);
}

const Player*
GameData::getPlayer(const char* name) const
{
  const Player*	player;
  unsigned int	t;
  unsigned int	i;

  player = NULL;

  for (t = 0; player == NULL && t < m_teamsNumber; ++t)
    {
      for (i = 0; i < m_teams[t].getPlayers().getSize(); ++i)
	if (!strcmp(m_teams[t].getPlayers()[i].getName(), name))
	  player = &m_teams[t].getPlayers()[i];
    }

  return (player);
}


void
GameData::doToPlayers(void (*function)(Player& player))
{
  unsigned int	t;
  unsigned int	i;

  for (t = 0; t < m_teamsNumber; ++t)
    {
      for (i = 0; i < m_teams[t].getPlayers().getSize(); ++i)
	function(m_teams[t].getPlayers()[i]);
    }
}


static void     prepare(Player& player)
{
  player.setDecremented(false);
}

void
GameData::preparePlayers()
{
  this->doToPlayers(&prepare);
}



void
GameData::setSpawnPoints(const Map& map)
{
  unsigned int	i;

  for (i = 0; i < m_teamsNumber; ++i)
    m_teams[i].setSpawnPoint(map.createSpawnPoint(360 * i / m_teamsNumber));
}


static void
sayStart(Player& player)
{
  player.send("START true");
}

void
GameData::startGame()
{
  if (m_started == false)
    {
      m_started = true;
      LogManagerSingleton::access()->events->print("Game started !");
      this->doToPlayers(&sayStart);
    }
  else
    LogManagerSingleton::access()->error->print("Game already started !");
}
