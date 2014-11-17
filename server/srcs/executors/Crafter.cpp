//
// Crafter.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Fri Nov 14 10:37:22 2014 
// Last Update Fri Nov 14 13:06:09 2014 
//

#include "abstractions/strings.hh"
#include "executors/Crafter.hh"

Crafter::Crafter()
{
}

Crafter::~Crafter()
{
}


void
Crafter::execute(Player* player, const Action::UData& data)
{
  const Craft&	craft = m_catalog.getElem(data.id);
  unsigned int	i;

  for (i = 0; i < Hoopla::items_number; ++i)
    if (craft.getRequires()[i] > 0)
      player->getInventory().sub(static_cast<Hoopla::EItem>(i), craft.getRequires()[i]);

  player->getInventory().add(static_cast<Hoopla::EItem>(data.id), 1);

  player->send("END true");
}
