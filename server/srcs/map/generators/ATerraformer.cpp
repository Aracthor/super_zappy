//
// ATerraformer.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Wed Oct 22 14:19:07 2014 
// Last Update Mon Nov  3 10:29:13 2014 
//

#include "abstractions/allocs.hh"
#include "map/generators/ATerraformer.hh"

ATerraformer::ATerraformer(const Configs::Map& configs) :
  MoistureCalculator(configs.width * CHUNK_SIZE, configs.height * CHUNK_SIZE),
  WaterGenerator(configs.width, configs.height),
  m_configs(configs),
  m_hooplasNumber(configs.width * configs.height * CHUNK_SIZE * CHUNK_SIZE)
{
  MALLOC(m_hooplas, m_hooplasNumber, Hoopla);
}

ATerraformer::~ATerraformer()
{
  free(m_hooplas);
}
