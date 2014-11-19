//
// DiggerTimeCalculator.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Fri Nov 14 16:52:06 2014 
// Last Update Tue Nov 18 12:45:05 2014 
//

#include "actions/timecalcs/DiggerTimeCalculator.hh"
#include "core/Server.hh"

DiggerTimeCalculator::DiggerTimeCalculator()
{
}

DiggerTimeCalculator::~DiggerTimeCalculator()
{
}


unsigned int
DiggerTimeCalculator::calcTime(Player* player,
			       const Action::UData& data __attribute__ ((unused)))
{
  Hoopla::EItem	item;
  unsigned int	time;

  item = (m_catalog[this->getServerData()->getHoopla(player->getPosition()).ground]
	  .getDigItem());

  if (player->getInventory().canHandleMore(item, 1))
    {
      time = (m_catalog[this->getServerData()->getHoopla(player->getPosition()).ground]
	      .getDigTime());
      this->getServerData()->vsayToGraphicClients("PDG %s %d\n",
						  player->getName(), time);
    }
  else
    {
      player->send("ITEM NULL");
      time = 0;
    }

  return (time);
}
