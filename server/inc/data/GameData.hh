//
// GameData.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Wed Oct 22 13:24:52 2014 
// Last Update Tue Nov  4 10:49:04 2014 
//

#ifndef GAME_DATA_HH_
# define GAME_DATA_HH_

# include "Team.hh"
# include "containers/Array.hh"
# include "init/Configs.hh"

class		GameData
{
protected:
  Array<Team>	m_teams;
  unsigned int	m_teamsNumber;
  unsigned int  m_speed;

protected:
  GameData(const Configs& configs);
  virtual ~GameData();

public:
  Team*	getTeamFromName(const char* name);

public:
  inline const Team*	getTeams() const;
  inline unsigned int	getTeamsNumber() const;
  inline unsigned int	getSpeed() const;
};

# include "GameData.hpp"

#endif // !GAME_DATA_HH_
