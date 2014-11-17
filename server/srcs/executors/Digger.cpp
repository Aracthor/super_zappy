//
// Digger.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Fri Nov 14 17:36:30 2014 
// Last Update Fri Nov 14 17:58:21 2014 
//

#include "executors/Digger.hh"

Digger::Digger()
{
}

Digger::~Digger()
{
}


void
Digger::execute(Player* player, const Action::UData& data __attribute__ ((unused)))
{
  Hoopla::EItem	item;

  item = (m_catalog[this->getServerData()->getHoopla(player->getPosition()).ground]
	  .getDigItem());
  player->getInventory().add(item, 1);

  player->vsend("ITEM %d", item);
}
