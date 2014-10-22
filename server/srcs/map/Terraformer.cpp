//
// Terraformer.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Oct 12 08:21:23 2014 
// Last Update Sun Oct 12 08:56:14 2014 
//

#include "abstractions/allocs.hh"
#include "abstractions/Random.hh"
#include "map/Chunk.hh"
#include "map/Hoopla.hh"
#include "map/Terraformer.hh"

Terraformer::Terraformer(const Configs::Map& configs) :
  m_configs(configs)
{
  MALLOC(m_hooplas, m_configs.longer * m_configs.larger * CHUNK_SIZE * CHUNK_SIZE, Hoopla);
}

Terraformer::~Terraformer()
{
  free(m_hooplas);
}


void
Terraformer::createMap(unsigned long seed)
{
  Random	random(seed);
  unsigned int	i;

  for (i = 0; i < m_configs.longer * m_configs.larger * CHUNK_SIZE * CHUNK_SIZE; ++i)
    {
      m_hooplas[i].ground = static_cast<Hoopla::EGround>
	(random.getNumber() % Hoopla::grounds_number);
      m_hooplas[i].height = random.getNumber() % 100;
      m_hooplas[i].item = static_cast<Hoopla::EItem>
	(random.getNumber() % Hoopla::items_number);
      m_hooplas[i].itemNumber = random.getNumber() % MAX_ITEMS_BY_HOOPLA;
      m_hooplas[i].object = static_cast<Hoopla::EObject>
	(random.getNumber() % Hoopla::objects_number);
      m_hooplas[i].player_id = 0;
    }
}

const Hoopla&
Terraformer::getHoopla(unsigned int x, unsigned int y)
{
  return (m_hooplas[y * m_configs.longer * CHUNK_SIZE + x]);
}
