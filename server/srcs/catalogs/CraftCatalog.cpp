//
// CraftCatalog.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Fri Nov 14 10:57:47 2014 
// Last Update Tue Dec  9 14:24:35 2014 
//

#include "catalogs/CraftCatalog.hh"

CraftCatalog::CraftCatalog() :
  Catalog<Craft, Hoopla::items_number>("crafts")
{
}

CraftCatalog::~CraftCatalog()
{
}
