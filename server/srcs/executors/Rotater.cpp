//
// Rotater.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Nov  9 03:12:41 2014 
// Last Update Sun Nov  9 04:27:42 2014 
//

#include "core/Server.hh"
#include "executors/Rotater.hh"

Rotater::Rotater()
{
}

Rotater::~Rotater()
{
}


void
Rotater::execute(Player* player, const Action::UData& data)
{
  player->rotate(data.id);
  this->getServerData()->vsayToGraphicClients("PPO %s %d %d %d\n",
					      player->getName(),
					      player->getPosition().x,
					      player->getPosition().y,
					      player->getOrientation());
}
