//
// SyscallException.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Oct 12 06:33:33 2014 
// Last Update Sun Oct 12 06:34:23 2014 
//

#ifndef SYSCALL_EXCEPTION_HH_
# define SYSCALL_EXCEPTION_HH_

# include "ZappyException.hh"

class	SyscallException : public ZappyException
{
public:
  SyscallException(const char* message);
  virtual ~SyscallException() throw();
};

#endif // !SYSCALL_EXCEPTION_HH_
