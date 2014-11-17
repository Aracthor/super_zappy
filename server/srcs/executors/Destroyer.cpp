//
// Destroyer.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Nov  9 09:48:40 2014 
// Last Update Sun Nov 16 16:06:39 2014 
//

#include "abstractions/strings.hh"
#include "core/Server.hh"
#include "debug/LogManager.hh"
#include "executors/Destroyer.hh"

#include <cstdlib>
#include <cstring>

Destroyer::Destroyer()
{
  memset(m_destroyers, 0, sizeof(m_destroyers));
  m_destroyers[Hoopla::bush]	= &Destroyer::bushDestroyer;
}

Destroyer::~Destroyer()
{
}


void
Destroyer::turnFaceToCoord(Player* player, const sf::Vector2u& coord)
{
  Action::UData	data;
  sf::Vector2u	position;
  unsigned int	distance;

  distance = DISTANCE(position, coord);
  if (distance == 2)
    {
      data.id = 1;
      this->getServerData()->insertAction(Action(player, Action::rotate, 1, data));
      this->getServerData()->insertAction(Action(player, Action::rotate, 1, data));
    }

  else if (distance == 1)
    {
      if (position + m_movements.getMovement(Player::right) == coord)
	data.id = 1;
      else
	data.id = -1;
      this->getServerData()->insertAction(Action(player, Action::rotate, 1, data));
    }
}

bool
Destroyer::getHoopla(Player* player, Hoopla** hoopla, const sf::Vector2u& coord)
{
  bool		valid;

  valid = (DISTANCE(player->getPosition(), coord) == 1);

  if (valid)
    {
      this->turnFaceToCoord(player, coord);
      *hoopla = &this->getServerData()->getHoopla(coord);
    }

  return (valid);
}


void
Destroyer::bushDestroyer(Player* player, Hoopla* hoopla)
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

  valid = this->getHoopla(player, &hoopla, sf::Vector2u(data.position.x, data.position.y));

  if (valid)
    {
      valid = (m_destroyers[hoopla->object] != NULL);
      if (valid)
	{
	  (this->*m_destroyers[hoopla->object])(player, hoopla);
	  hoopla->object = Hoopla::none;
	}
      else
	LogManagerSingleton::access()->error->print("Invalid destroyer for object %d",
						    data.id);
    }

  if (valid)
    this->getServerData()->sayToGraphicClients(*hoopla);

  player->vsend("END %s", BOOLEAN_TO_STRING(valid));
}
