//
// Teams.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Oct 12 05:33:47 2014 
// Last Update Mon Nov  3 16:02:33 2014 
//

#ifndef TEAMS_HH_
# define TEAMS_HH_

class		Teams
{
private:
  const char**	m_names;
  unsigned int	m_number;

public:
  Teams();
  ~Teams();

public:
  void	addTeam(const char* team);

public:
  int			getId(const char* team) const;
  inline const char*	getName(unsigned int id) const;
  inline unsigned int	getNumber() const;
};

#include "Teams.hpp"

#endif // !TEAMS_HH_
