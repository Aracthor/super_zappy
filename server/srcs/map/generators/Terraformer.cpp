//
// Terraformer.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Oct 12 08:21:23 2014 
// Last Update Sun Oct 26 01:22:13 2014 
//

#include "abstractions/Random.hh"
#include "map/Chunk.hh"
#include "map/generators/MountainMap.hh"
#include "map/generators/PerlinMap.hh"
#include "map/generators/Terraformer.hh"

#include <cstring>

Terraformer::Terraformer(const Configs::Map& configs) :
  ATerraformer(configs)
{
}

Terraformer::~Terraformer()
{
}


void
Terraformer::createMap()
{
  HeightMap*	map;
  HeightMap*	perlin;

  memset(m_hooplas, 0, m_hooplasNumber * sizeof(Hoopla));
  for (unsigned int i = 0; i < m_hooplasNumber; ++i)
    m_hooplas[i].moisture = 60;

  map = new MountainMap(m_configs.longer * CHUNK_SIZE, m_configs.larger * CHUNK_SIZE);
  perlin = new PerlinMap(m_configs.longer * CHUNK_SIZE, m_configs.larger * CHUNK_SIZE,
			 PERLIN_STEP, PERLIN_OCTAVES);
  map->initHeights();
  perlin->initHeights();
  *map += *perlin; 
  map->copyHeights(m_hooplas);
  delete (map);
  delete (perlin);

  this->setGrounds(m_hooplas, m_hooplasNumber);
  this->setObjects(m_hooplas, m_hooplasNumber);
}
