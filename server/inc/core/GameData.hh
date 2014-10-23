//
// GameData.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Wed Oct 22 13:24:52 2014 
// Last Update Wed Oct 22 13:30:30 2014 
//

#ifndef GAME_DATA_HH_
# define GAME_DATA_HH_

# include "init/Configs.hh"

class			GameData
{
protected:
  const Teams		m_teams;
  unsigned int		m_speed;

protected:
  GameData(const Configs& configs);
  virtual ~GameData();

public:
  inline const Teams&	getTeams() const;
  inline unsigned int	getSpeed() const;
};

# include "GameData.hpp"

#endif // !GAME_DATA_HH_
