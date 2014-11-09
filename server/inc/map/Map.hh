//
// Map.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Oct 12 07:46:24 2014 
// Last Update Sun Nov  9 08:39:39 2014 
//

#ifndef MAP_HH_
# define MAP_HH_

# include <SFML/System/Vector2.hpp>

# include "Chunk.hh"
# include "init/Configs.hh"

# define IS_GOOD_CHUNK_POS(x, y, map)	(x < (map)->getWidth() && y < (map)->getHeight())
# define IS_GOOD_HOOPLA_POS(x, y, map)	((int)x >= 0 && (int)y >= 0 && (unsigned int)x < (map)->getWidth() * CHUNK_SIZE && (unsigned int)y < (map)->getHeight() * CHUNK_SIZE)

class		Map
{
private:
  Chunk*	m_chunks;
  unsigned int	m_width;
  unsigned int	m_height;

public:
  Map(const Configs& configs);
  ~Map();

private:
  void	terraform(const Configs::Map& configs);

private:
  bool		tryToSpawn(const sf::Vector2u& origin, sf::Vector2u& pos,
			   unsigned int depth) const;

public:
  sf::Vector2u	createSpawnPoint(unsigned int angle) const;
  sf::Vector2u	getSpawnPoint(const sf::Vector2u& origin);

public:
  inline const Chunk&	getChunk(unsigned int x, unsigned int y) const;
  inline Chunk&		getChunk(unsigned int x, unsigned int y);
  inline const Hoopla&	getHoopla(unsigned int x, unsigned int y) const;
  inline Hoopla&	getHoopla(unsigned int x, unsigned int y);
  inline unsigned int	getWidth() const;
  inline unsigned int	getHeight() const;

  template <typename T>
  inline const Chunk&	getChunk(const sf::Vector2<T>& pos) const;
  template <typename T>
  inline const Hoopla&	getHoopla(const sf::Vector2<T>& pos) const;
  template <typename T>
  inline Hoopla&	getHoopla(const sf::Vector2<T>& pos);
};

#include "Map.hpp"

#endif // !MAP_HH_
