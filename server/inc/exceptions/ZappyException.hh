//
// ZappyException.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Oct 12 06:02:07 2014 
// Last Update Wed Dec 17 12:22:54 2014 
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
  ZappyException(const char* message, const char* arg);
  ZappyException(const std::string& message);
  ZappyException(const std::string& message, const char* arg);
  virtual ~ZappyException() throw();

public:
  const char*	what() const throw();
};

#endif // !ZAPPY_EXCEPTION_HH_
