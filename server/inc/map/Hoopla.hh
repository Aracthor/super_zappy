//
// Hoopla.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Oct 12 07:28:24 2014 
// Last Update Sun Oct 26 01:31:27 2014 
//

#ifndef HOOPLA_HH_
# define HOOPLA_HH_

# define MAX_ITEMS_BY_HOOPLA	(5)

# define MAX_HEIGHT		(9)
# define MIN_HEIGHT		(0)
# define MAX_MOISTURE		(9)
# define MIN_MOISTURE		(0)

# define LOW_GROUND		(Hoopla::ocean)
# define HIGH_GROUND		(Hoopla::snow)

class	Hoopla
{
public:
  enum	EGround
  {
    snow,
    bare,
    tundra,
    taiga,
    shrubland,
    rocky_desert,
    temperate_jungle,
    temperate_forest,
    tallgrass,
    grassland,
    plain,
    desert,
    tropical_jungle,
    tropical_forest,
    marsh,
    beach,
    ocean,
    grounds_number
  };

public:
  enum	EItem
  {
    none,
    items_number
  };

public:
  enum	EObject
  {
    nothing,
    bush,
    shrub,
    oak,
    ash,
    saplin,
    maple,
    objects_number
  };

public:
  EGround	ground;
  int		moisture;
  int		height;
  EItem		item;
  unsigned int	itemNumber;
  EObject	object;
  unsigned int	player_id;

public:
  Hoopla();
  ~Hoopla();
};

#endif // !HOOPLA_HH_
