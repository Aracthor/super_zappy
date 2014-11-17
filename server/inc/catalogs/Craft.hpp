//
// Craft.hpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Fri Nov 14 11:01:22 2014 
// Last Update Fri Nov 14 12:56:35 2014 
//

void
Craft::addRequire(Hoopla::EItem item, unsigned int number)
{
  m_requires[item] = number;
}


const unsigned int*
Craft::getRequires() const
{
  return (m_requires);
}

unsigned int
Craft::getTime() const
{
  return (m_time);
}

unsigned int
Craft::getLevel() const
{
  return (m_level);
}
