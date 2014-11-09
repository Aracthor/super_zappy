//
// Clock.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sat Nov  8 20:48:32 2014 
// Last Update Sat Nov  8 21:02:54 2014 
//

#ifndef CLOCK_HH_
# define CLOCK_HH_

# include <sys/time.h>

class			Clock
{
private:
  struct timeval	m_lastTime;
  unsigned long		m_elapsedTime;

public:
  Clock();
  virtual ~Clock();

public:
  void			update();

public:
  inline unsigned long	getElapsedTime() const;
};

# include "Clock.hpp"

#endif // !CLOCK_HH_
