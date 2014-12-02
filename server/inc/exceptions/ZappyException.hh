//
// ZappyException.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Oct 12 06:02:07 2014 
// Last Update Fri Nov 21 12:25:44 2014 
//

#ifndef ZAPPY_EXCEPTION_HH_
# define ZAPPY_EXCEPTION_HH_

# include <exception>
# include <string>

class		ZappyException : public std::exception
{
protected:
  std::string	m_message;

public:
  ZappyException(const char* message);
  ZappyException(const std::string& message);
  virtual ~ZappyException() throw();

public:
  const char*	what() const throw();
};

#endif // !ZAPPY_EXCEPTION_HH_
