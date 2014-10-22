//
// Map.hpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Oct 12 07:48:07 2014 
// Last Update Wed Oct 22 12:43:40 2014 
//

const Chunk&
Map::getChunk(unsigned int x, unsigned int y) const
{
  return (m_chunks[y * m_longer + x]);
}

unsigned int
Map::getLonger() const
{
  return (m_longer);
}

unsigned int
Map::getLarger() const
{
  return (m_larger);
}
