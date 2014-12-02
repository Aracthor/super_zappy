//
// SignalException.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Fri Nov 21 12:24:24 2014 
// Last Update Fri Nov 21 12:24:37 2014 
//

#ifndef SIGNAL_EXCEPTION_HH_
# define SIGNAL_EXCEPTION_HH_

# include "ZappyException.hh"

class	SignalException : public ZappyException
{
public:
  SignalException(int signum);
  ~SignalException() throw();
};

#endif // !SIGNAL_EXCEPTION_HH_
