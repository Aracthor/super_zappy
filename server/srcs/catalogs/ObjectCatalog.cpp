//
// ObjectCatalog.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Thu Dec  4 09:58:11 2014 
// Last Update Tue Dec  9 10:00:44 2014 
//

#include "catalogs/ObjectCatalog.hh"

ObjectCatalog::ObjectCatalog() :
  Catalog<Object, Hoopla::objects_number>("objects")
{
  // this->insert(Object(Production(Hoopla::stick,	2, 4),  30,  true), Hoopla::bush);
  // this->insert(Object(Production(Hoopla::stick,	3, 5),	 50,  true), Hoopla::shrub);
  // this->insert(Object(Production(Hoopla::log,	3, 5), 100, false), Hoopla::oak);
  // this->insert(Object(Production(Hoopla::log,	2, 4),  70, false), Hoopla::ash);
  // this->insert(Object(Production(Hoopla::log,	2, 3),  50, false), Hoopla::saplin);
  // this->insert(Object(Production(Hoopla::log,	2, 5),  90, false), Hoopla::maple);
}

ObjectCatalog::~ObjectCatalog()
{
}
