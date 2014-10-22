//
// Map.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Oct 12 07:48:32 2014 
// Last Update Sun Oct 12 08:21:07 2014 
//

#include "abstractions/allocs.hh"
#include "map/Map.hh"
#include "map/Terraformer.hh"

Map::Map(const Configs::Map& configs) :
  m_longer(configs.longer),
  m_larger(configs.larger)
{
  Terraformer	terraformer(configs);
  Chunk*	chunk;
  unsigned int	x, y;

  MALLOC(m_chunks, m_longer * m_larger, Chunk);

  terraformer.createMap();
  for (x = 0; x < m_longer * CHUNK_SIZE; ++x)
    for (y = 0; y < m_larger * CHUNK_SIZE; ++y)
      {
	chunk = &m_chunks[y / CHUNK_SIZE * m_longer + x / CHUNK_SIZE];
	chunk->setHoopla(terraformer.getHoopla(x, y),
			 x % CHUNK_SIZE, y % CHUNK_SIZE);
      }
}

Map::~Map()
{
  free(m_chunks);
}
