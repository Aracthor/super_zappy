//
// Mover.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Nov  9 03:11:42 2014 
// Last Update Sun Nov  9 05:28:39 2014 
//

#include "executors/Mover.hh"
#include "core/Server.hh"

Mover::Mover()
{
}

Mover::~Mover()
{
}


void
Mover::execute(Player* player, const Action::UData& data)
{
  bool	moved;

  moved = player->move();

  if (moved)
    {
      this->getServerData()->vsayToGraphicClients("PPO %s %d %d %d\n",
						  player->getName(),
						  player->getPosition().x,
						  player->getPosition().y,
						  player->getOrientation());
      if (data.boolean == true)
	player->send("END true");
    }
  else
    {
      // TODO Refaire le calcul
    }
}
