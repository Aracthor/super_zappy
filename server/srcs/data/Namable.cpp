//
// Namable.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Tue Nov  4 08:51:34 2014 
// Last Update Thu Dec 11 09:14:44 2014 
//

#include "data/Namable.hh"

#include <cstdlib>
#include <cstring>

Namable::Namable() :
  m_name(NULL)
{
}

Namable::Namable(const char* name) :
  m_name(strdup(name))
{
}

Namable::Namable(const Namable& copy) :
  m_name(copy.getName() ? strdup(copy.getName()) : NULL)
{
}

Namable::~Namable()
{
  this->destroy();
}


void
Namable::destroy()
{
  if (m_name != NULL)
    {
      free(m_name);
      m_name = NULL;
    }
}
