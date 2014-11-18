//
// GameData.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Wed Oct 22 13:24:52 2014 
// Last Update Mon Nov 17 17:53:46 2014 
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
  void		doToPlayers(void (*function)(Player& player));
  template <typename T>
  void		doToPlayers(void (*function)(Player& player, const T& data), const T& data);
  template <typename T, typename U>
  void		doToPlayers(void (*function)(Player& player, const T& data1, const U* data2),
			    const T& data1, const U* data2);

public:
  void		preparePlayers();

protected:
  void		setSpawnPoints(const Map& map);

public:
  void		startGame();

public:
  inline const Team*	getTeams() const;
  inline Team*		getTeamFromName(const char* name);
  inline unsigned int	getTeamsNumber() const;
  inline bool		isStarted() const;
  inline Player*	getPlayerFromName(const char* name);
};

# include "GameData.hpp"

#endif // !GAME_DATA_HH_
