//
// Equipper.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Wed Nov 12 17:43:04 2014 
// Last Update Thu Nov 13 09:36:36 2014 
//

#include "abstractions/strings.hh"
#include "debug/outputs.hh"
#include "executors/Equipper.hh"

Equipper::Equipper()
{
}

Equipper::~Equipper()
{
}


bool
Equipper::unequipe(Player* player)
{
  bool	valid;

  valid = true;

  if (player->getEquipement() != Hoopla::none)
    {
      valid = (!player->getInventory().isFull() &&
	       (!player->getInventory().hasNoMoreSlot() ||
		player->getInventory().getItemNumber(player->getEquipement()) > 0));
      if (valid)
	{
	  player->getInventory().add(player->getEquipement(), 1);
	  player->setEquipement(Hoopla::none);
	}
    }

  return (valid);
}

bool
Equipper::changeEquipement(Player* player, Hoopla::EItem item)
{
  Hoopla::EItem	equipement;
  unsigned int	number;
  bool		valid;

  number = player->getInventory().getItemNumber(item);
  valid = (number > 0);

  if (valid)
    {
      equipement = player->getEquipement();
      if (equipement != Hoopla::none)
	valid = (!player->getInventory().hasNoMoreSlot() || number == 1);
      if (valid)
	{
	  player->getInventory().sub(item, 1);
	  player->setEquipement(item);
	  if (equipement != Hoopla::none)
	    player->getInventory().add(equipement, 1);
	}
    }

  return (valid);
}


void
Equipper::execute(Player* player, const Action::UData& data)
{
  Hoopla::EItem	item;
  bool		valid;

  item = static_cast<Hoopla::EItem>(data.id);

  if (item == Hoopla::none)
    valid = this->unequipe(player);
  else
    valid = this->changeEquipement(player, item);
  
  player->vsend("END %s", BOOLEAN_TO_STRING(valid));
  if (valid)
    this->getServerData()->vsayToGraphicClients("PEQ %s %d\n",
						player->getName(), player->getEquipement());
}
