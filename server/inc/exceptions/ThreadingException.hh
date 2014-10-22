//
// ThreadingException.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Oct 12 10:37:13 2014 
// Last Update Sun Oct 12 10:40:07 2014 
//

#ifndef THREADING_EXCEPTION_HH_
# define THREADING_EXCEPTION_HH_

# include "ZappyException.hh"

class	ThreadingException : public ZappyException
{
public:
  ThreadingException(const char* message, int error);
  ~ThreadingException() throw();
};

#endif // !THREADING_EXCEPTION_HH_
