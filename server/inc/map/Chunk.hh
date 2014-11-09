//
// Chunk.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Oct 12 07:42:30 2014 
// Last Update Sat Nov  8 18:46:45 2014 
//

#ifndef CHUNK_HH_
# define CHUNK_HH_

# include "Hoopla.hh"

# define CHUNK_SIZE	(16)

class		Chunk
{
private:
  Hoopla	m_hooplas[CHUNK_SIZE][CHUNK_SIZE];

public:
  Chunk();
  ~Chunk();

public:
  void	setHoopla(const Hoopla& hoopla, unsigned int x, unsigned int y);

public:
  inline const Hoopla&	getHoopla(unsigned int x, unsigned int y) const;
  inline Hoopla&	getHoopla(unsigned int x, unsigned int y);
};

# include "Chunk.hpp"

#endif // !CHUNK_HH_
