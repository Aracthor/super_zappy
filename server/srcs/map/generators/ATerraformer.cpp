//
// ATerraformer.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Wed Oct 22 14:19:07 2014 
// Last Update Tue Oct 28 14:21:38 2014 
//

#include "abstractions/allocs.hh"
#include "map/generators/ATerraformer.hh"

ATerraformer::ATerraformer(const Configs::Map& configs) :
  MoistureCalculator(configs.longer * CHUNK_SIZE, configs.larger * CHUNK_SIZE),
  WaterGenerator(configs.longer, configs.larger),
  m_configs(configs),
  m_hooplasNumber(configs.longer * configs.larger * CHUNK_SIZE * CHUNK_SIZE)
{
  MALLOC(m_hooplas, m_hooplasNumber, Hoopla);
}

ATerraformer::~ATerraformer()
{
  free(m_hooplas);
}
