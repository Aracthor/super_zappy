//
// NetworkException.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Oct 12 06:05:27 2014 
// Last Update Sun Oct 12 06:36:11 2014 
//

#ifndef NETWORK_EXCEPTION_HH_
# define NETWORK_EXCEPTION_HH_

# include "SyscallException.hh"

class	NetworkException : public SyscallException
{
public:
  NetworkException(const char* message);
  ~NetworkException() throw();
};

#endif // !NETWORK_EXCEPTION_HH_
