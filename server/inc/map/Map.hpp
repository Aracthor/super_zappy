//
// Map.hpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Oct 12 07:48:07 2014 
// Last Update Sat Nov  8 18:46:08 2014 
//

const Chunk&
Map::getChunk(unsigned int x, unsigned int y) const
{
  return (m_chunks[y * m_width + x]);
}

Chunk&
Map::getChunk(unsigned int x, unsigned int y)
{
  return (m_chunks[y * m_width + x]);
}

const Hoopla&
Map::getHoopla(unsigned int x, unsigned int y) const
{
  return (this->getChunk(x / CHUNK_SIZE, y / CHUNK_SIZE)
	  .getHoopla(x % CHUNK_SIZE, y % CHUNK_SIZE));
}

Hoopla&
Map::getHoopla(unsigned int x, unsigned int y)
{
  return (this->getChunk(x / CHUNK_SIZE, y / CHUNK_SIZE)
	  .getHoopla(x % CHUNK_SIZE, y % CHUNK_SIZE));
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


template <typename T>
const Chunk&
Map::getChunk(const sf::Vector2<T>& pos) const
{
  return (this->getChunk(pos.x, pos.y));
}

template <typename T>
const Hoopla&
Map::getHoopla(const sf::Vector2<T>& pos) const
{
  return (this->getHoopla(pos.x, pos.y));
}

template <typename T>
Hoopla&
Map::getHoopla(const sf::Vector2<T>& pos)
{
  return (this->getHoopla(pos.x, pos.y));
}
