//
// Namable.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Tue Nov  4 08:51:34 2014 
// Last Update Tue Nov  4 15:57:24 2014 
//

#include "data/Namable.hh"

#include <cstdlib>
#include <cstring>

#include <cstdio> // DEBUG
Namable::Namable(const char* name) :
  m_name(strdup(name))
{
}

Namable::Namable(const Namable& copy) :
  m_name(strdup(copy.getName()))
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
