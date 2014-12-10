//
// Equipper.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Wed Nov 12 17:43:04 2014 
// Last Update Wed Dec 10 11:27:21 2014 
//

#include "abstractions/strings.hh"
#include "data/Weapon.hh"
#include "debug/outputs.hh"
#include "executors/Equipper.hh"

Equipper::Equipper()
{
}

Equipper::~Equipper()
{
}


Equipement*
Equipper::createEquipement(Hoopla::EItem item) const
{
  Equipement*	equipement;

  if (m_catalog.elemExists(item))
    equipement = new Weapon(item, m_catalog[item]); // TODO rechargeable weapons
  else
    equipement = new Equipement(item);

  return (equipement);
}


bool
Equipper::unequipe(Player* player)
{
  Hoopla::EItem	item;
  bool		valid;

  item = player->getEquipementItem();
  valid = true;

  if (item != Hoopla::none)
    {
      valid = (!player->getInventory().isFull() &&
	       (!player->getInventory().hasNoMoreSlot() ||
		player->getInventory().getItemNumber(item) > 0));
      if (valid)
	{
	  player->getInventory().add(item, 1);
	  player->unequip();
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
      equipement = player->getEquipementItem();
      if (equipement != Hoopla::none)
	valid = (!player->getInventory().hasNoMoreSlot() || number == 1);
      if (valid)
	{
	  player->getInventory().sub(item, 1);
	  player->setEquipement(this->createEquipement(item));
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
}
