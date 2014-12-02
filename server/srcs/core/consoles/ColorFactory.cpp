//
// ColorFactory.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Wed Nov 19 10:34:23 2014 
// Last Update Thu Nov 20 11:23:16 2014 
//

#include "abstractions/allocs.hh"
#include "core/consoles/ColorFactory.hh"

ColorFactory::ColorFactory(unsigned int number)
{
  unsigned int	i;

  MALLOC(m_colors, number, nc::Color);

  m_colors[0] = nc::Color(COLOR_RED, COLOR_BLACK);
  if (number > 1)
    m_colors[1] = nc::Color(COLOR_GREEN, COLOR_BLACK);
  if (number > 2)
    m_colors[2] = nc::Color(COLOR_YELLOW, COLOR_BLACK);
  if (number > 3)
    m_colors[3] = nc::Color(COLOR_BLUE, COLOR_BLACK);
  if (number > 4)
    m_colors[4] = nc::Color(COLOR_MAGENTA, COLOR_BLACK);
  if (number > 5)
    m_colors[5] = nc::Color(COLOR_CYAN, COLOR_BLACK);

  for (i = 6; i < number; ++i)
    m_colors[i] = nc::Color(COLOR_WHITE, COLOR_BLACK);
}

ColorFactory::~ColorFactory()
{
  free(m_colors);
}


const nc::Color&
ColorFactory::getColor(unsigned int index) const
{
  return (m_colors[index]);
}
