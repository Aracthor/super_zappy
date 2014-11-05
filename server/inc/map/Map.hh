//
// Map.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Oct 12 07:46:24 2014 
// Last Update Mon Nov  3 10:27:59 2014 
//

#ifndef MAP_HH_
# define MAP_HH_

# include "Chunk.hh"
# include "init/Configs.hh"

# define IS_GOOD_CHUNK_POS(x, y, map)	(x < (map)->getWidth() && y < (map)->getHeight())
# define IS_GOOD_HOOPLA_POS(x, y, map)	(x < (map)->getWidth() * CHUNK_SIZE && y < (map)->getHeight() * CHUNK_SIZE)

class		Map
{
private:
  Chunk*	m_chunks;
  unsigned int	m_width;
  unsigned int	m_height;

public:
  Map(const Configs::Map& configs);
  ~Map();

public:
  inline const Chunk&	getChunk(unsigned int x, unsigned int y) const;
  inline unsigned int	getWidth() const;
  inline unsigned int	getHeight() const;
};

#include "Map.hpp"

#endif // !MAP_HH_
