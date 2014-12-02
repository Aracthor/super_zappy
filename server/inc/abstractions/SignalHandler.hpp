//
// SignalHandler.hpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server/code_qui_fait_segfault_valgrind
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Fri Nov 21 09:55:43 2014 
// Last Update Fri Nov 21 10:23:35 2014 
//

#include "exceptions/SyscallException.hh"

template <int SIGNUM>
SignalHandler<SIGNUM>*
SignalHandler<SIGNUM>::s_handler;

template <int SIGNUM>
static void	handler(int signum __attribute__ ((unused)))
{
  if (signal(SIGNUM, SIG_DFL) == SIG_ERR)
    throw SyscallException("Error stopping handling signal when this signal was caught : ");
  SignalHandler<SIGNUM>::s_handler->onCatch();
}

template <int SIGNUM>
SignalHandler<SIGNUM>::SignalHandler()
{
  s_handler = this;
  if (signal(SIGNUM, &(handler<SIGNUM>)) == SIG_ERR)
    throw SyscallException("Error handling signal : ");
}

template <int SIGNUM>
SignalHandler<SIGNUM>::~SignalHandler()
{
  if (signal(SIGNUM, SIG_DFL) == SIG_ERR)
    throw SyscallException("Error stopping handling signal : ");
}
