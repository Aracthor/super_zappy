//
// SignalHandler.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server/code_qui_fait_segfault_valgrind
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Fri Nov 21 09:43:58 2014 
// Last Update Fri Nov 21 10:10:19 2014 
//

#ifndef SIGNAL_HANDLER_HH_
# define SIGNAL_HANDLER_HH_

# include <csignal>

template <int SIGNUM>
class	SignalHandler
{
public:
  static SignalHandler*	s_handler;

public:
  SignalHandler();
  virtual ~SignalHandler();

public:
  virtual void	onCatch() = 0;
};

# include "SignalHandler.hpp"

#endif // !SIGNAL_HANDLER_HH_
