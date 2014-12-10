//
// WeaponCatalog.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Tue Dec  9 14:23:19 2014 
// Last Update Tue Dec  9 14:44:34 2014 
//

#include "catalogs/WeaponCatalog.hh"

WeaponCatalog::WeaponCatalog() :
  Catalog<WeaponPlan, Hoopla::items_number>("weapons")
{
}

WeaponCatalog::~WeaponCatalog()
{
}
