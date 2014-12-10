//
// GameData.hpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Wed Oct 22 13:26:40 2014 
// Last Update Wed Dec 10 10:46:57 2014 
//


template <typename T>
T
GameData::doToTeams(T (*function)(const Team& team)) const
{
  T		total;
  unsigned int	i;

  total = 0;
  for (i = 0; i < m_teamsNumber; ++i)
    total += function(m_teams[i]);

  return (total);
}


template <typename T>
void
GameData::doToPlayers(void (*function)(Player& player, const T& data), const T& data)
{
  unsigned int	t;
  unsigned int	i;

  for (t = 0; t < m_teamsNumber; ++t)
    {
      for (i = 0; i < m_teams[t].getPlayers().getSize(); ++i)
	function(m_teams[t].getPlayers()[i], data);
    }
}

template <typename T>
void
GameData::doToPlayers(void (*function)(const Player& player, const T& data), const T& data) const
{
  unsigned int	t;
  unsigned int	i;

  for (t = 0; t < m_teamsNumber; ++t)
    {
      for (i = 0; i < m_teams[t].getPlayers().getSize(); ++i)
	function(m_teams[t].getPlayers()[i], data);
    }
}

template <typename T, typename U>
void
GameData::doToPlayers(void (*function)(Player& player, const T& data1, const U* data2),
		      const T& data1, const U* data2)
{
  unsigned int	t;
  unsigned int	i;

  for (t = 0; t < m_teamsNumber; ++t)
    {
      for (i = 0; i < m_teams[t].getPlayers().getSize(); ++i)
	function(m_teams[t].getPlayers()[i], data1, data2);
    }
}


template <typename T>
const Player*
GameData::findPlayer(int (*function)(const Player& player, const T& data), const T& data) const
{
  const Player*	player;
  int		bestScore;
  int		score;
  unsigned int	t;
  unsigned int	i;

  bestScore = 0;
  player = NULL;

  for (t = 0; t < m_teamsNumber; ++t)
    {
      for (i = 0; i < m_teams[t].getPlayers().getSize(); ++i)
	{
	  score = function(m_teams[t].getPlayers()[i], data);
	  if (score > bestScore)
	    {
	      score = bestScore;
	      player = &m_teams[t].getPlayers()[i];
	    }
	}
    }

  return (player);
}

template <typename T>
Player*
GameData::findPlayer(int (*function)(const Player& player, const T& data), const T& data)
{
  Player*	player;
  int		bestScore;
  int		score;
  unsigned int	t;
  unsigned int	i;

  bestScore = 0;
  player = NULL;

  for (t = 0; t < m_teamsNumber; ++t)
    {
      for (i = 0; i < m_teams[t].getPlayers().getSize(); ++i)
	{
	  score = function(m_teams[t].getPlayers()[i], data);
	  if (score > bestScore)
	    {
	      score = bestScore;
	      player = &m_teams[t].getPlayers()[i];
	    }
	}
    }

  return (player);
}


const Team*
GameData::getTeams() const
{
  return (m_teams.getData());
}

Team*
GameData::getTeamFromName(const char* name)
{
  return ((Team*)this->getTeam(name));
}

unsigned int
GameData::getTeamsNumber() const
{
  return (m_teamsNumber);
}

static unsigned int
countPlayers(const Team& team)
{
  return (team.getPlayers().getSize());
}

unsigned int
GameData::getPlayersNumber() const
{
  return (this->doToTeams(&countPlayers));
}

bool
GameData::isStarted() const
{
  return (m_started);
}

bool
GameData::isAnyPlayer() const
{
  return (this->getPlayersNumber() > 0);
}

Player*
GameData::getPlayerFromName(const char* name)
{
  return (const_cast<Player*>(this->getPlayer(name)));
}
