//
// NcursesException.cpp for plazza in /home/bonnet_v/programs/projects/cpp/ncurses
// 
// Made by Bonnet Vivien
// Login   <bonnet_v@epitech.net>
// 
// Started on  Tue Apr 15 10:50:59 2014 Bonnet Vivien
// Last Update Sat Aug 23 20:54:41 2014 
//

#include "ncursesxx/NcursesException.hh"

namespace nc
{

NcursesException::NcursesException(const std::string& message) :
  m_message(message)
{
}

NcursesException::~NcursesException() throw()
{
}


const char*
NcursesException::what() const throw()
{
  return (m_message.c_str());
}

}
