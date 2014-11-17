//
// CraftTimeCalculator.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Fri Nov 14 10:17:20 2014 
// Last Update Fri Nov 14 16:29:35 2014 
//

#include "actions/timecalcs/CraftTimeCalculator.hh"

CraftTimeCalculator::CraftTimeCalculator()
{
}

CraftTimeCalculator::~CraftTimeCalculator()
{
}

#include <cstdio> // DEBUG

bool
CraftTimeCalculator::checkRequires(const Player* player, const unsigned int* requires) const
{
  bool		valid;
  unsigned int	i;

  valid = true;
  for (i = 0; i < Hoopla::items_number; ++i)
    if (requires[i] > player->getInventory().getItemNumber(static_cast<Hoopla::EItem>(i)))
      valid = false;

  return (valid);
}

bool
CraftTimeCalculator::checkPlaceForProduce(const Player* player, Hoopla::EItem item) const
{
  bool		valid;
  unsigned int	i;

  valid = (!player->getInventory().hasNoMoreSlot() &&
	   player->getInventory().getItemNumber(item) == 0);

  if (valid == false)
    for (i = 0; i < Hoopla::items_number; ++i)
      if (m_catalog.getElem(item).getRequires()[i] ==
	  player->getInventory().getItemNumber(static_cast<Hoopla::EItem>(i)))
	valid = true;

  return (valid);
}

bool
CraftTimeCalculator::checkCapacity(const Player* player, Hoopla::EItem item) const
{
  Craft		craft;

  return (m_catalog.getSecureElem(craft, item) &&
	  player->getClass()->getSkillLevel(Class::crafting) >= craft.getLevel() &&
	  this->checkRequires(player, craft.getRequires()) &&
	  this->checkPlaceForProduce(player, item));
}


unsigned int
CraftTimeCalculator::calcTime(Player* player, const Action::UData& data)
{
  bool		valid;
  unsigned int	time;

  valid = this->checkCapacity(player, static_cast<Hoopla::EItem>(data.id));

  if (valid)
    time = (m_catalog.getElem(data.id).getTime() /
	    player->getClass()->getSkillLevel(Class::crafting));
  else
    {
      player->send("END false");
      time = 0;
    }

  return (time);
}
