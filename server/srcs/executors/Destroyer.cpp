//
// Destroyer.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Nov  9 09:48:40 2014 
// Last Update Tue Dec  9 16:34:18 2014 
//

#include "abstractions/strings.hh"
#include "debug/LogManager.hh"
#include "debug/usefull.hh"
#include "executors/Destroyer.hh"

#include <cstdlib>
#include <cstring>

Destroyer::Destroyer()
{
}

Destroyer::~Destroyer()
{
}


void
Destroyer::execute(Player* player, const Action::UData& data)
{
  Hoopla&	hoopla = this->getServerData()->getHoopla(data.position.x, data.position.y);
  bool		valid;

  valid = checkOrPrint(hoopla.object != Hoopla::none, "No object to destroy at position %d/%d",
		       data.position.x, data.position.y);

  if (valid)
    {
      hoopla.item	= m_catalog[hoopla.object].getProduction().getItem();
      hoopla.itemNumber	= m_catalog[hoopla.object].getProduction().getRandomNumber();
      hoopla.object = Hoopla::none;
      this->getServerData()->sayToGraphicClients(hoopla);
    }

  player->vsend("END %s", BOOLEAN_TO_STRING(valid));
}
