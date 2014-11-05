//
// Namable.hpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Tue Nov  4 08:45:22 2014 
// Last Update Tue Nov  4 15:58:09 2014 
//

#include <cstring>

const char*
Namable::getName() const
{
  return (m_name);
}


Namable&
Namable::operator=(const Namable& copy)
{
  m_name = strdup(copy.getName());
  return *this;
}
