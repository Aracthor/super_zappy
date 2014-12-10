//
// WeaponCatalog.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Tue Dec  9 14:23:12 2014 
// Last Update Tue Dec  9 14:44:37 2014 
//

#ifndef WEAPON_CATALOG_HH_
# define WEAPON_CATALOG_HH_

# include "WeaponPlan.hh"
# include "containers/Catalog.hh"

class	WeaponCatalog : public Catalog<WeaponPlan, Hoopla::items_number>
{
public:
  WeaponCatalog();
  ~WeaponCatalog();
};

#endif // !WEAPON_CATALOG_HH_
