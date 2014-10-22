//
// Teams.hpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Oct 12 06:49:33 2014 
// Last Update Sun Oct 12 06:49:35 2014 
//

const char*
Teams::getName(unsigned int id) const
{
  return (m_names[id]);
}

unsigned int
Teams::getNumber() const
{
  return (m_number);
}
