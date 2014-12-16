//
// AttackTimeCalculator.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Tue Dec 16 08:55:02 2014 
// Last Update Tue Dec 16 10:10:23 2014 
//

#include "actions/timecalcs/AttackTimeCalculator.hh"
#include "core/Server.hh"

AttackTimeCalculator::AttackTimeCalculator()
{
}

AttackTimeCalculator::~AttackTimeCalculator()
{
}


unsigned int
AttackTimeCalculator::calcTime(Player* player, const Action::UData& data __attribute__ ((unused)))
{
  unsigned int	time;
  Hoopla::EItem	item;

  item = player->getEquipement() ? player->getEquipement()->getItem() : Hoopla::none;
  if (m_catalog.elemExists(item) == false)
    {
      player->send("END false");
      time = 0;
    }
  else
    {
      time = m_catalog[item].getProjectileSpeed();
      this->getServerData()->vsayToGraphicClients("PAT %s %d %d %d %d\n", player->getName(), time, item,
						  data.position.x, data.position.y);
    }

  return (time);
}
