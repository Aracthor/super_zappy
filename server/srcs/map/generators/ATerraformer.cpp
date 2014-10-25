//
// ATerraformer.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Wed Oct 22 14:19:07 2014 
// Last Update Fri Oct 24 10:09:04 2014 
//

#include "abstractions/allocs.hh"
#include "map/generators/ATerraformer.hh"

ATerraformer::ATerraformer(const Configs::Map& configs) :
  m_configs(configs),
  m_hooplasNumber(configs.longer * configs.larger * CHUNK_SIZE * CHUNK_SIZE)
{
  MALLOC(m_hooplas, m_hooplasNumber, Hoopla);
}

ATerraformer::~ATerraformer()
{
  free(m_hooplas);
}
