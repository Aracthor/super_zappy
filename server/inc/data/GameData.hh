//
// GameData.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Wed Oct 22 13:24:52 2014 
// Last Update Wed Nov 19 10:38:50 2014 
//

#ifndef GAME_DATA_HH_
# define GAME_DATA_HH_

# include "Team.hh"
# include "containers/Array.hh"
# include "core/LinkedToServer.hh"
# include "init/Configs.hh"
# include "map/Map.hh"

class		GameData : private LinkedToServer
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
  unsigned int	getTeamId(const Team& team) const;

public:
  void		doToTeams(void (*function)(Team& team));
  void		doToPlayers(void (*function)(Player& player));
  void		doToPlayers(void (*function)(const Player& player)) const;
  template <typename T>
  void		doToPlayers(void (*function)(Player& player, const T& data), const T& data);
  template <typename T>
  void		doToPlayers(void (*function)(const Player& player, const T& data), const T& data) const;
  template <typename T, typename U>
  void		doToPlayers(void (*function)(Player& player, const T& data1, const U* data2),
			    const T& data1, const U* data2);

public:
  void		preparePlayers();

protected:
  void		setSpawnPoints(const Map& map);

public:
  void		startGame();
  void		resetGame();

public:
  void		reset();

public:
  inline const Team*	getTeams() const;
  inline Team*		getTeamFromName(const char* name);
  inline unsigned int	getTeamsNumber() const;
  inline bool		isStarted() const;
  inline Player*	getPlayerFromName(const char* name);
};

# include "GameData.hpp"

#endif // !GAME_DATA_HH_
