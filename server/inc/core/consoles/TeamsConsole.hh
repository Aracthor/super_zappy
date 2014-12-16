//
// TeamsConsole.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Thu Dec 11 09:19:24 2014 
// Last Update Thu Dec 11 09:24:28 2014 
//

#ifndef TEAMS_CONSOLE_HH_
# define TEAMS_CONSOLE_HH_

# include "ColorFactory.hh"
# include "DataConsole.hh"
# include "data/Team.hh"

class			TeamsConsole : public DataConsole<Team>
{
private:
  ColorFactory		m_colors;
  mutable unsigned int	m_index;

public:
  TeamsConsole();
  ~TeamsConsole();

public:
  void	drawElemData(const Team& team) const;

public:
  void	drawData() const;
};

#endif // !TEAMS_CONSOLE_HH_
