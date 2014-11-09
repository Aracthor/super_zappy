//
// Chunk.hpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Wed Oct 22 12:46:42 2014 
// Last Update Sat Nov  8 18:46:51 2014 
//

const Hoopla&
Chunk::getHoopla(unsigned int x, unsigned int y) const
{
  return (m_hooplas[y][x]);
}

Hoopla&
Chunk::getHoopla(unsigned int x, unsigned int y)
{
  return (m_hooplas[y][x]);
}
