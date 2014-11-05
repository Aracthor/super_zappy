//
// Player.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Tue Nov  4 08:37:23 2014 
// Last Update Tue Nov  4 10:30:58 2014 
//

#ifndef PLAYER_HH_
# define PLAYER_HH_

# include "Class.hh"
# include "Namable.hh"

class	Player : public Namable
{
private:
  const Class*	m_class;

public:
  Player(const char* name, const Class* refToClass);
  ~Player();
};

#endif // !PLAYER_HH_
