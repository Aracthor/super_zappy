//
// Map.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Oct 12 07:46:24 2014 
// Last Update Wed Oct 22 12:58:30 2014 
//

#ifndef MAP_HH_
# define MAP_HH_

# include "Chunk.hh"
# include "init/Configs.hh"

# define IS_GOOD_CHUNK_POS(x, y, map)	(x < (map)->getLonger() && y < (map)->getLarger())
# define IS_GOOD_HOOPLA_POS(x, y, map)	(x < (map)->getLonger() * CHUNK_SIZE && y < (map)->getLarger() * CHUNK_SIZE)

class		Map
{
private:
  Chunk*	m_chunks;
  unsigned int	m_longer;
  unsigned int	m_larger;

public:
  Map(const Configs::Map& configs);
  ~Map();

public:
  inline const Chunk&	getChunk(unsigned int x, unsigned int y) const;
  inline unsigned int	getLonger() const;
  inline unsigned int	getLarger() const;
};

#include "Map.hpp"

#endif // !MAP_HH_
