//
// ColorFactory.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Wed Nov 19 10:32:58 2014 
// Last Update Wed Nov 19 10:34:08 2014 
//

#ifndef COLOR_FACTORY_HH_
# define COLOR_FACTORY_HH_

# include "ncursesxx/Color.hh"

class		ColorFactory
{
private:
  nc::Color*	m_colors;

public:
  ColorFactory(unsigned int number);
  ~ColorFactory();

public:
  const nc::Color&	getColor(unsigned int index) const;
};

#endif // !COLOR_FACTORY_HH_
