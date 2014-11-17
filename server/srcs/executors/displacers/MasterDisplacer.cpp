//
// MasterDisplacer.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Nov  9 01:16:57 2014 
// Last Update Sun Nov 16 16:06:25 2014 
//

#include "debug/LogManager.hh"
#include "executors/displacers/MasterDisplacer.hh"

MasterDisplacer::MasterDisplacer()
{
}

MasterDisplacer::~MasterDisplacer()
{
}


bool
MasterDisplacer::search(const sf::Vector2u& origin, const sf::Vector2u& dest)
{
  LogManagerSingleton::access()->error->print("Master Displacer TODOOOOO !!!");
  (void)(origin);
  (void)(dest);

  return (false);
}
