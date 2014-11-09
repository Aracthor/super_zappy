//
// GameData.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Wed Oct 22 13:24:52 2014 
// Last Update Sun Nov  9 03:29:45 2014 
//

#ifndef GAME_DATA_HH_
# define GAME_DATA_HH_

# include "Team.hh"
# include "containers/Array.hh"
# include "map/Map.hh"
# include "init/Configs.hh"

class		GameData
{
protected:
  Array<Team>	m_teams;
  unsigned int	m_teamsNumber;
  bool		m_started;

protected:
  GameData(const Configs& configs);
  virtual ~GameData();

public:
  const Team*	getTeam(const char* name) const;
  const Player*	getPlayer(const char* name) const;

public:
  void		preparePlayers();

protected:
  void		setSpawnPoints(const Map& map);

public:
  inline const Team*	getTeams() const;
  inline Team*		getTeamFromName(const char* name);
  inline unsigned int	getTeamsNumber() const;
  inline bool		isStarted() const;
  inline Player*	getPlayerFromName(const char* name);

public:
  inline void		startGame();
};

# include "GameData.hpp"

#endif // !GAME_DATA_HH_
