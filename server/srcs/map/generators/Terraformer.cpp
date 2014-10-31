//
// Terraformer.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Oct 12 08:21:23 2014 
// Last Update Thu Oct 30 18:21:29 2014 
//

#include "abstractions/allocs.hh"
#include "debug/LogManager.hh"
#include "map/Chunk.hh"
#include "map/generators/MountainMap.hh"
#include "map/generators/PerlinMap.hh"
#include "map/generators/RingMap.hh"
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
Terraformer::calcHeights()
{
  HeightMap*	map;
  HeightMap*	perlin;

  memset(m_hooplas, 0, m_hooplasNumber * sizeof(Hoopla));

  map = new MountainMap(m_configs.longer * CHUNK_SIZE, m_configs.larger * CHUNK_SIZE);
  map->initHeights();
  perlin = new PerlinMap(m_configs.longer * CHUNK_SIZE, m_configs.larger * CHUNK_SIZE,
			 PERLIN_STEP, PERLIN_OCTAVES);
  perlin->initHeights();
  *map += *perlin; 

  map->copyHeights(m_hooplas);

  delete (map);
  delete (perlin);
}


void
Terraformer::createMap()
{
  float*	moistures;

  MALLOC(moistures, m_hooplasNumber, float);

  LogManagerSingleton::access()->intern.print("Map generation started...");
  LogManagerSingleton::access()->intern.print("Height calc...");
  this->calcHeights();
  this->setDefaultGrounds(m_hooplas, m_hooplasNumber);
  LogManagerSingleton::access()->intern.print("River insertions...");
  this->insertWater(m_hooplas);
  LogManagerSingleton::access()->intern.print("Low lake emplition...");
  this->emplLowLakes();
  LogManagerSingleton::access()->intern.print("Moistures calc...");
  this->calcMoistures(m_hooplas, moistures);
  LogManagerSingleton::access()->intern.print("Grounds definition...");
  this->setGrounds(m_hooplas, moistures, m_hooplasNumber);
  LogManagerSingleton::access()->intern.print("Objects creation...");
  this->setObjects(m_hooplas, m_hooplasNumber);
  LogManagerSingleton::access()->intern.print("Map generation ended.");

  free(moistures);
}
