//
// Taker.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Wed Nov 12 15:52:07 2014 
// Last Update Wed Nov 12 16:31:19 2014 
//

#include "executors/Taker.hh"

Taker::Taker()
{
}

Taker::~Taker()
{
}


void
Taker::execute(Player* player, const Action::UData& data __attribute__((unused)))
{
  Hoopla&	hoopla = this->getServerData()->getHoopla(player->getPosition());
  unsigned int	number;
  bool		valid;

  valid = (hoopla.item != Hoopla::none &&
	   !player->getInventory().isFull() && !player->getInventory().hasNoMoreSlot());

  if (valid)
    {
      number = player->getInventory().add(static_cast<Hoopla::EItem>(hoopla.item),
					  hoopla.itemNumber);
      player->vsend("ITEMS %d %d", hoopla.item, number);
      hoopla.itemNumber -= number;
      if (hoopla.itemNumber == 0)
	hoopla.item = Hoopla::none;
      this->getServerData()->sayToGraphicClients(hoopla);
    }
  else
    player->send("ITEMS NULL");
}
