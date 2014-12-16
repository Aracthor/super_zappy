//
// ATerraformer.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Wed Oct 22 14:19:07 2014 
// Last Update Tue Dec 16 10:23:08 2014 
//

#include "abstractions/allocs.hh"
#include "map/generators/ATerraformer.hh"

#include <cstdlib>
#include <cstring>
#include <ctime>
#include <unistd.h>

ATerraformer::ATerraformer(const Configs::Map& configs) :
  MoistureCalculator(configs.width * CHUNK_SIZE, configs.height * CHUNK_SIZE),
  WaterGenerator(configs.width, configs.height),
  m_configs(configs),
  m_hooplasNumber(configs.width * configs.height * CHUNK_SIZE * CHUNK_SIZE)
{
  this->initSeed(configs.seed);
  MALLOC(m_hooplas, m_hooplasNumber, Hoopla);
  memset(m_hooplas, 0, m_hooplasNumber * sizeof(Hoopla));
  this->copyPositions();
}

ATerraformer::~ATerraformer()
{
  free(m_hooplas);
}


void
ATerraformer::initSeed(unsigned int seed)
{
  m_seed = seed;
  if (m_seed == 0)
    m_seed = time(NULL) * getpid();
  srandom(m_seed);
}

void
ATerraformer::copyPositions()
{
  unsigned int	x;
  unsigned int	y;

  for (x = 0; x < m_configs.width * CHUNK_SIZE; ++x)
    for (y = 0; y < m_configs.height * CHUNK_SIZE; ++y)
      {
	m_hooplas[y * m_configs.width * CHUNK_SIZE + x].x = x;
	m_hooplas[y * m_configs.width * CHUNK_SIZE + x].y = y;
      }
}
