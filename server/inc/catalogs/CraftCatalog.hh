//
// CraftCatalog.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Fri Nov 14 10:57:42 2014 
// Last Update Fri Nov 14 17:08:49 2014 
//

#ifndef CRAFT_CATALOG_HH_
# define CRAFT_CATALOG_HH_

# include "Craft.hh"
# include "containers/Catalog.hh"
# include "map/Hoopla.hh"

class	CraftCatalog : public Catalog<Craft, Hoopla::items_number>
{
public:
  CraftCatalog();
  ~CraftCatalog();
};

#endif // !CRAFT_CATALOG_HH_
