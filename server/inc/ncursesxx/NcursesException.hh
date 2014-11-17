//
// NcursesException.hh for plazza in /home/bonnet_v/programs/projects/cpp/ncurses
// 
// Made by Bonnet Vivien
// Login   <bonnet_v@epitech.net>
// 
// Started on  Tue Apr 15 10:48:39 2014 Bonnet Vivien
// Last Update Sun Aug 24 01:13:12 2014 
//

#ifndef NCURSES_EXCEPTION_HH_
# define NCURSES_EXCEPTION_HH_

# include <exception>
# include <string>

namespace nc
{

class			NcursesException : public std::exception
{
private:
  const std::string	m_message;

public:
  NcursesException(const std::string& message);
  virtual ~NcursesException() throw();

public:
  virtual const char*	what() const throw();
};

}

#endif // !NCURSES_EXCEPTION_HH_
