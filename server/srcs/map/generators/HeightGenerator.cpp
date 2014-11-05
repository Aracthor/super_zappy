//
// HeightGenerator.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Mon Nov  3 14:47:18 2014 
// Last Update Mon Nov  3 15:47:14 2014 
//

#include "map/Chunk.hh"
#include "map/generators/HeightGenerator.hh"
#include "map/generators/MountainMap.hh"
#include "map/generators/PerlinMap.hh"
#include "map/generators/RingMap.hh"

#include <cstring>

HeightGenerator::HeightGenerator()
{
}

HeightGenerator::~HeightGenerator()
{
}


void
HeightGenerator::calcHeights(Hoopla* hooplas, unsigned int width, unsigned int height)
{
  HeightMap*	map;
  HeightMap*	perlin;

  width *= CHUNK_SIZE;
  height *= CHUNK_SIZE;

  memset(hooplas, 0, width * height * sizeof(Hoopla));

  map = new MountainMap(width, height);
  map->initHeights();
  perlin = new PerlinMap(width, height,
			 PERLIN_STEP, PERLIN_OCTAVES);
  perlin->initHeights();
  *map += *perlin; 

  map->copyHeights(hooplas);

  delete (map);
  delete (perlin);
}
