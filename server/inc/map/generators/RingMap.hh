//
// RingMap.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Fri Oct 24 13:28:15 2014 
// Last Update Thu Oct 30 17:26:06 2014 
//

#ifndef RING_MAP_HH_
# define RING_MAP_HH_

# include "HeightMap.hh"

class	RingMap : public HeightMap
{
public:
  RingMap(unsigned int longer, unsigned int larger);
  ~RingMap();

protected:
  float	calcHeight(unsigned int x, unsigned int y);
};

#endif // !RING_MAP_HH_
