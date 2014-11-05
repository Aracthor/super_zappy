//
// Teams.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Oct 12 06:16:40 2014 
// Last Update Mon Nov  3 16:02:40 2014 
//

#include "abstractions/allocs.hh"
#include "init/Teams.hh"

#include <cstdlib>
#include <cstring>

Teams::Teams() :
  m_names(NULL),
  m_number(0)
{
}

Teams::~Teams()
{
  if (m_names != NULL)
    free(m_names);
}


void
Teams::addTeam(const char* team)
{
  ++m_number;
  REALLOC(m_names, m_number, const char*);
  m_names[m_number - 1] = team;
}


int
Teams::getId(const char* team) const
{
  unsigned int	i;
  int		id;

  id = -1;
  for (i = 0; id == -1 && i < m_number; ++i)
    {
      if (!strcmp(team, m_names[i]))
	id = i;
    }

  return (id);
}
