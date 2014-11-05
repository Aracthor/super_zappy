//
// Map.hpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Oct 12 07:48:07 2014 
// Last Update Mon Nov  3 10:28:18 2014 
//

const Chunk&
Map::getChunk(unsigned int x, unsigned int y) const
{
  return (m_chunks[y * m_width + x]);
}

unsigned int
Map::getWidth() const
{
  return (m_width);
}

unsigned int
Map::getHeight() const
{
  return (m_height);
}
