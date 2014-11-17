//
// Color.cpp for plazza in /home/bonnet_v/programs/projects/cpp/ncurses
// 
// Made by Bonnet Vivien
// Login   <bonnet_v@epitech.net>
// 
// Started on  Tue Apr 15 13:52:11 2014 Bonnet Vivien
// Last Update Sun Nov 16 17:35:44 2014 
//

#include "ncursesxx/Color.hh"
#include "ncursesxx/NcursesException.hh"

namespace nc
{

int
Color::g_counter = 0;

Color::Color()
{
}

Color::Color(short foreground, short background)
{
  m_foreground = foreground;
  m_background = background;
  m_id = ++g_counter;
  if (init_pair(m_id, m_foreground, m_background) == ERR)
    throw NcursesException("Cannot create color");
}

Color::~Color()
{
}

}
