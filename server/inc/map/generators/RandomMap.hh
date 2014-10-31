//
// RandomMap.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Fri Oct 24 13:28:15 2014 
// Last Update Mon Oct 27 13:36:18 2014 
//

#ifndef RANDOM_MAP_HH_
# define RANDOM_MAP_HH_

# include "HeightMap.hh"

class	RandomMap : public HeightMap
{
public:
  RandomMap(unsigned int longer, unsigned int larger);
  ~RandomMap();

protected:
  float	calcHeight(unsigned int x, unsigned int y);
};

#endif // !RANDOM_MAP_HH_
