//
// ObjectCatalog.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Thu Dec  4 09:41:33 2014 
// Last Update Thu Dec  4 09:44:17 2014 
//

#ifndef OBJECT_CATALOG_HH_
# define OBJECT_CATALOG_HH_

# include "Object.hh"
# include "containers/Catalog.hh"

class	ObjectCatalog : public Catalog<Object, Hoopla::objects_number>
{
public:
  ObjectCatalog();
  ~ObjectCatalog();
};

#endif // !OBJECT_CATALOG_HH_
