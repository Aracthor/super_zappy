//
// ATerraformer.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Wed Oct 22 14:19:07 2014 
// Last Update Wed Oct 22 14:25:20 2014 
//

#include "abstractions/allocs.hh"
#include "map/ATerraformer.hh"

ATerraformer::ATerraformer(const Configs::Map& configs) :
  m_configs(configs)
{
  MALLOC(m_hooplas, m_configs.longer * m_configs.larger * CHUNK_SIZE * CHUNK_SIZE, Hoopla);
}

ATerraformer::~ATerraformer()
{
  free(m_hooplas);
}
