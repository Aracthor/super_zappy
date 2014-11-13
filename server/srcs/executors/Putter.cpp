//
// Putter.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Wed Nov 12 16:02:02 2014 
// Last Update Wed Nov 12 17:45:06 2014 
//

#include "abstractions/strings.hh"
#include "executors/Putter.hh"

Putter::Putter()
{
}

Putter::~Putter()
{
}


void
Putter::execute(Player* player, const Action::UData& data)
{
  Hoopla&	hoopla = this->getServerData()->getHoopla(player->getPosition());
  bool		valid;

  valid = (hoopla.item == Hoopla::nothing &&
	   data.item.number > 0 &&
	   player->getInventory().getItemNumber(data.item.id) >= data.item.number);

  if (valid)
    {
      hoopla.item = data.item.id;
      hoopla.itemNumber = data.item.number;
      player->getInventory().sub(data.item.id, data.item.number);
      this->getServerData()->sayToGraphicClients(hoopla);
    }

  player->vsend("END %s", BOOLEAN_TO_STRING(valid));
}
