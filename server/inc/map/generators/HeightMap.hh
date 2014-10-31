//
// HeightMap.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Fri Oct 24 10:10:02 2014 
// Last Update Mon Oct 27 13:35:54 2014 
//

#ifndef HEIGHT_MAP_HH_
# define HEIGHT_MAP_HH_

# include "map/Hoopla.hh"

class		HeightMap
{
private:
  float*	m_heights;

protected:
  unsigned int	m_size;
  unsigned int	m_longer;
  unsigned int	m_larger;

public:
  HeightMap(unsigned int longer, unsigned int larger);
  virtual ~HeightMap();

protected:
  virtual float	calcHeight(unsigned int x, unsigned int y);

public:
  void	initHeights();

public:
  void	copyHeights(Hoopla* hooplas) const;

public:
  HeightMap&	operator+=(const HeightMap& map);
};

#endif // !HEIGHT_MAP_HH_
