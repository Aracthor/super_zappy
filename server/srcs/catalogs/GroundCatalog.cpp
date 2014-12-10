//
// GroundCatalog.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Fri Nov 14 17:08:13 2014 
// Last Update Tue Dec  9 14:24:30 2014 
//

#include "catalogs/GroundCatalog.hh"

GroundCatalog::GroundCatalog() :
  Catalog<Ground, Hoopla::grounds_number>("grounds")
{
}

GroundCatalog::~GroundCatalog()
{
}
