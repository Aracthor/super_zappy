//
// Map.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Oct 12 07:48:32 2014 
// Last Update Wed Nov 19 13:40:48 2014 
//

#include "abstractions/allocs.hh"
#include "abstractions/maths.hh"
#include "debug/LogManager.hh"
#include "map/Map.hh"
#include "map/generators/Terraformer.hh"

Map::Map(const Configs& configs) :
  m_chunks(NULL)
{
  this->terraform(configs.getMapConfigs());
}

Map::~Map()
{
  free(m_chunks);
}


void
Map::terraform(const Configs::Map& configs)
{
  m_configs = configs;
  this->terraform();
}


bool
Map::tryToSpawn(const sf::Vector2u& origin, sf::Vector2u& pos, unsigned int depth) const
{
  bool		spawned;

  spawned = (IS_EMPTY(this->getHoopla(origin + sf::Vector2u( 1,  1))) &&
	     IS_EMPTY(this->getHoopla(origin + sf::Vector2u( 0,  1))) &&
	     IS_EMPTY(this->getHoopla(origin + sf::Vector2u(-1,  1))) &&
	     IS_EMPTY(this->getHoopla(origin + sf::Vector2u(-1,  0))) &&
	     IS_EMPTY(this->getHoopla(origin + sf::Vector2u(-1, -1))) &&
	     IS_EMPTY(this->getHoopla(origin + sf::Vector2u( 0, -1))) &&
	     IS_EMPTY(this->getHoopla(origin + sf::Vector2u( 1, -1))) &&
	     IS_EMPTY(this->getHoopla(origin + sf::Vector2u( 1,  0))) &&
	     IS_EMPTY(this->getHoopla(origin)) && this->getHoopla(origin).height > 0);

  if (spawned)
    pos = origin;
  else if (depth > 0)
    {
      spawned = (this->tryToSpawn(origin + sf::Vector2u( 0,  1), pos, depth - 1) ||
		 this->tryToSpawn(origin + sf::Vector2u( 0, -1), pos, depth - 1) ||
		 this->tryToSpawn(origin + sf::Vector2u( 1,  0), pos, depth - 1) ||
		 this->tryToSpawn(origin + sf::Vector2u(-1,  0), pos, depth - 1));
    }

  return (spawned);
}


void
Map::terraform()
{
  Terraformer	terraformer(m_configs);
  Chunk*	chunk;
  unsigned int	x, y;

  REALLOC(m_chunks, m_configs.width * m_configs.height, Chunk);

  terraformer.createMap();
  for (x = 0; x < m_configs.width * CHUNK_SIZE; ++x)
    for (y = 0; y < m_configs.height * CHUNK_SIZE; ++y)
      {
	chunk = &m_chunks[y / CHUNK_SIZE * m_configs.width + x / CHUNK_SIZE];
	chunk->setHoopla(terraformer.getHoopla(x, y),
			 x % CHUNK_SIZE, y % CHUNK_SIZE);
      }

  LogManagerSingleton::access()->events->print("New map created : %d/%d.", m_configs.width, m_configs.height);
}

void
Map::resize(unsigned int width, unsigned int height)
{
  m_configs.width = width;
  m_configs.height = height;
}


sf::Vector2u
Map::createSpawnPoint(unsigned int angle) const
{
  sf::Vector2f	pos;
  sf::Vector2f	movement;
  float		width, height;

  width = static_cast<float>(m_configs.width);
  height = static_cast<float>(m_configs.height);

  pos.x = (width / 2.0f + cos(RAD(angle)) * width / 2.0f) * CHUNK_SIZE;
  pos.y = (height / 2.0f + sin(RAD(angle)) * height / 2.0f) * CHUNK_SIZE;

  movement.x = -cos(RAD(angle));
  movement.y = -sin(RAD(angle));

  while (this->getHoopla(pos).ground == Hoopla::ocean)
    pos += movement;

  return (sf::Vector2u(pos.x, pos.y));
}

sf::Vector2u
Map::getSpawnPoint(const sf::Vector2u& origin)
{
  sf::Vector2u	point;
  unsigned int	i;
  bool		spawned;

  for (i = 0, spawned = false;
       spawned == false;
       ++i)
    spawned = this->tryToSpawn(origin, point, i);

  this->getHoopla(point).hasPlayer = true;

  return (point);
}
