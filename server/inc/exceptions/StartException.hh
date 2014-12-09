//
// StartException.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Tue Nov 18 10:28:38 2014 
// Last Update Fri Dec  5 13:28:25 2014 
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
