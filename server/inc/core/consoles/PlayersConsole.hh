//
// PlayerConsole.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Wed Nov 19 10:19:09 2014 
// Last Update Thu Dec 11 09:22:12 2014 
//

#ifndef PLAYERS_CONSOLE_HH_
# define PLAYERS_CONSOLE_HH_

# include "ColorFactory.hh"
# include "DataConsole.hh"
# include "data/Player.hh"

class			PlayersConsole : public DataConsole<Player>
{
private:
  ColorFactory		m_colors;
  mutable unsigned int	m_index;

public:
  PlayersConsole();
  ~PlayersConsole();

public:
  void	drawElemData(const Player& player) const;

public:
  void	drawData() const;
};

#endif // !PLAYERS_CONSOLE_HH_
