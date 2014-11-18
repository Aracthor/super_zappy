//
// StartException.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Tue Nov 18 10:28:38 2014 
// Last Update Tue Nov 18 10:28:45 2014 
//

#ifndef START_EXCEPTION_HH_
# define START_EXCEPTION_HH_

# include "ZappyException.hh"

class	StartException : public ZappyException
{
public:
  StartException(const char* message);
  ~StartException() throw();
};

#endif // !START_EXCEPTION_HH_
