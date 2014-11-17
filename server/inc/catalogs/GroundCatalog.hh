//
// GroundCatalog.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Fri Nov 14 17:08:55 2014 
// Last Update Fri Nov 14 17:54:51 2014 
//

#ifndef GROUND_CATALOG_HH_
# define GROUND_CATALOG_HH_

# include "Ground.hh"
# include "containers/Catalog.hh"
# include "map/Hoopla.hh"

class	GroundCatalog : public Catalog<Ground, Hoopla::grounds_number>
{
public:
  GroundCatalog();
  ~GroundCatalog();
};

#endif // !GROUND_CATALOG_HH_
