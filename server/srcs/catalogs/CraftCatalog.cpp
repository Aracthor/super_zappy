//
// CraftCatalog.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Fri Nov 14 10:57:47 2014 
// Last Update Tue Dec  9 10:14:46 2014 
//

#include "catalogs/CraftCatalog.hh"

CraftCatalog::CraftCatalog() :
  Catalog<Craft, Hoopla::items_number>("crafts")
{
  // this->insert(Craft(15, 1), Hoopla::wooden_javelin);
  // this->accessElem(Hoopla::wooden_javelin).addRequire(Hoopla::stick, 1);
}

CraftCatalog::~CraftCatalog()
{
}
