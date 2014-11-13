//
// Destroyer.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Nov  9 09:48:40 2014 
// Last Update Wed Nov 12 10:08:07 2014 
//

#include "abstractions/strings.hh"
#include "core/Server.hh"
#include "debug/LogManager.hh"
#include "executors/Destroyer.hh"

#include <cstdlib>

Destroyer::Destroyer()
{
  m_destroyers[Hoopla::bush]	= &Destroyer::bushDestroyer;
}

Destroyer::~Destroyer()
{
}


bool
Destroyer::getHoopla(const Player* player, Hoopla** hoopla, unsigned char id)
{
  sf::Vector2u	position;
  bool		valid;

  position = player->getPosition() + m_movements.getMovement(player->getOrientation());
  *hoopla = &this->getServerData()->getHoopla(position);

  valid = ((*hoopla)->object == id);
  if (valid)
    (*hoopla)->object = Hoopla::nothing;

  return (valid);
}


void
Destroyer::bushDestroyer(const Player* player, Hoopla* hoopla)
{
  (void)(player);
  hoopla->item = Hoopla::stick;
  hoopla->itemNumber = random() % 3 + 2;
}


void
Destroyer::execute(Player* player, const Action::UData& data)
{
  Hoopla*	hoopla;
  bool		valid;

  valid = this->getHoopla(player, &hoopla, data.id);

  if (valid)
    {
      valid = (data.id < Hoopla::objects_number && m_destroyers[data.id] != NULL);
      if (valid)
	{
	  (this->*m_destroyers[data.id])(player, hoopla);
	  hoopla->object = Hoopla::none;
	}
      else
	LogManagerSingleton::access()->error.print("Invalid destroyer for object %d",
						   data.id);
    }

  this->getServerData()->sayToGraphicClients(*hoopla);
  player->vsend("END %s", BOOLEAN_TO_STRING(valid));
}
