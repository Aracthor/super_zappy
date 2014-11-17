//
// Color.hpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Nov 16 17:31:35 2014 
// Last Update Sun Nov 16 17:31:36 2014 
//

int
Color::getAttr() const
{
  return (COLOR_PAIR(m_id));
}
