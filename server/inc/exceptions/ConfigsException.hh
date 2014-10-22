//
// ConfigsException.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Oct 12 06:05:27 2014 
// Last Update Sun Oct 12 06:10:34 2014 
//

#ifndef CONFIGS_EXCEPTION_HH_
# define CONFIGS_EXCEPTION_HH_

# include "ZappyException.hh"

class	ConfigsException : public ZappyException
{
public:
  ConfigsException(const char* message);
  ~ConfigsException() throw();
};

#endif // !CONFIGS_EXCEPTION_HH_
