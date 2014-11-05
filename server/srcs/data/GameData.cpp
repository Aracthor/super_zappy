//
// GameData.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Wed Oct 22 13:29:09 2014 
// Last Update Tue Nov  4 15:37:56 2014 
//

#include "abstractions/allocs.hh"
#include "data/GameData.hh"
#include "debug/LogManager.hh"

#include <cstring>

GameData::GameData(const Configs& configs) :
  m_teamsNumber(configs.getTeams().getNumber()),
  m_speed(configs.getSpeed())
{
  unsigned int	i;

  LogManagerSingleton::access()->intern.print("Initialisating game data...");

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


Team*
GameData::getTeamFromName(const char* name)
{
  Team*		team;
  unsigned int	i;

  team = NULL;

  for (i = 0; team == NULL && i < m_teamsNumber; ++i)
    if (!strcmp(m_teams[i].getName(), name))
      team = &m_teams[i];

  return (team);
}
