//
// ObjectCatalog.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Thu Dec  4 09:58:11 2014 
// Last Update Tue Dec  9 14:24:24 2014 
//

#include "catalogs/ObjectCatalog.hh"

ObjectCatalog::ObjectCatalog() :
  Catalog<Object, Hoopla::objects_number>("objects")
{
}

ObjectCatalog::~ObjectCatalog()
{
}
