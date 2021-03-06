//
// MountainMap.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Fri Oct 24 13:28:15 2014 
// Last Update Mon Oct 27 13:36:24 2014 
//

#ifndef MOUNTAIN_MAP_HH_
# define MOUNTAIN_MAP_HH_

# include "HeightMap.hh"

class	MountainMap : public HeightMap
{
public:
  MountainMap(unsigned int longer, unsigned int larger);
  ~MountainMap();

protected:
  float	calcHeight(unsigned int x, unsigned int y);
};

#endif // !MOUNTAIN_MAP_HH_
