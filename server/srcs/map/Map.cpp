//
// Map.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Oct 12 07:48:32 2014 
// Last Update Mon Nov  3 16:12:13 2014 
//

#include "abstractions/allocs.hh"
#include "map/Map.hh"
#include "map/generators/Terraformer.hh"

Map::Map(const Configs::Map& configs) :
  m_width(configs.width),
  m_height(configs.height)
{
  Terraformer	terraformer(configs);
  Chunk*	chunk;
  unsigned int	x, y;

  MALLOC(m_chunks, m_width * m_height, Chunk);

  terraformer.createMap();
  for (x = 0; x < m_width * CHUNK_SIZE; ++x)
    for (y = 0; y < m_height * CHUNK_SIZE; ++y)
      {
	chunk = &m_chunks[y / CHUNK_SIZE * m_width + x / CHUNK_SIZE];
	chunk->setHoopla(terraformer.getHoopla(x, y),
			 x % CHUNK_SIZE, y % CHUNK_SIZE);
      }
}

Map::~Map()
{
  free(m_chunks);
}
