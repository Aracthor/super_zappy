//
// ZappyException.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Oct 12 06:02:07 2014 
// Last Update Sun Oct 12 10:54:45 2014 
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
  virtual ~ZappyException() throw();

public:
  const char*	what() const throw();
};

#endif // !ZAPPY_EXCEPTION_HH_
