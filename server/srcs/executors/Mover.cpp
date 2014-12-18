//
// Mover.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Nov  9 03:11:42 2014 
// Last Update Wed Dec 17 11:12:09 2014 
//

#include "core/Server.hh"
#include "debug/LogManager.hh"
#include "executors/Mover.hh"

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
      this->getServerData()->clearForPlayer(player);
      this->getServerData()->insertAction(Action(player, Action::displace, 1, player->getObjective()));
    }
}
