//
// Color.hh for plazza in /home/bonnet_v/programs/projects/cpp/ncurses
// 
// Made by Bonnet Vivien
// Login   <bonnet_v@epitech.net>
// 
// Started on  Tue Apr 15 13:50:28 2014 Bonnet Vivien
// Last Update Mon Nov 17 12:59:41 2014 
//

#ifndef COLOR_HH_
# define COLOR_HH_

# include <ncursesw/curses.h>

# define COLORS_NUMBER	(8)

namespace nc
{

class	Color
{
private:
  static int	g_counter;

private:
  int	m_id;
  short	m_foreground;
  short	m_background;

public:
  Color();
  Color(short foreground, short background);
  ~Color();

public:
  inline int	getAttr() const;
};

# include "Color.hpp"

}

#endif // !COLOR_HH_
