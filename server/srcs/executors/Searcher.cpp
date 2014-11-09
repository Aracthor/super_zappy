//
// Searcher.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Nov  9 08:13:05 2014 
// Last Update Sun Nov  9 09:10:36 2014 
//

#include "core/Server.hh"
#include "executors/Searcher.hh"

Searcher::Searcher()
{
}

Searcher::~Searcher()
{
}


bool
Searcher::research(sf::Vector2i& position, sf::Vector2i& movement,
		   const sf::Vector2i& origin,
		   unsigned char object, sf::Vector2u& pos, int* ptr)
{
  bool	found;

  found = false;

  while (found == false && *ptr != 0)
    {
      position += movement;
      found = this->find(position + origin, object);
    }

  if (found)
    pos = sf::Vector2u(position.x + origin.x, position.y + origin.y);

  return (found);
}


bool
Searcher::find(const sf::Vector2i& pos, unsigned char object) const
{
  return (IS_GOOD_HOOPLA_POS(pos.x, pos.y, this->getServerData()) &&
	  this->getServerData()->getHoopla(pos).object == object);
}


bool
Searcher::upToRight(const sf::Vector2i& origin, int range,
		    unsigned char object, sf::Vector2u& pos)
{
  sf::Vector2i	position(m_imovements[Player::up] * range);
  sf::Vector2i  movement(m_imovements[Player::down] + m_imovements[Player::right]);

  return (this->research(position, movement, origin, object, pos, &position.y));
}

bool
Searcher::rightToDown(const sf::Vector2i& origin, int range,
		    unsigned char object, sf::Vector2u& pos)
{
  sf::Vector2i	position(m_imovements[Player::right] * range);
  sf::Vector2i  movement(m_imovements[Player::left] + m_imovements[Player::down]);

  return (this->research(position, movement, origin, object, pos, &position.x));
}

bool
Searcher::downToLeft(const sf::Vector2i& origin, int range,
		     unsigned char object, sf::Vector2u& pos)
{
  sf::Vector2i	position(m_imovements[Player::down] * range);
  sf::Vector2i  movement(m_imovements[Player::up] + m_imovements[Player::left]);

  return (this->research(position, movement, origin, object, pos, &position.y));
}

bool
Searcher::leftToUp(const sf::Vector2i& origin, int range,
		   unsigned char object, sf::Vector2u& pos)
{
  sf::Vector2i	position(m_imovements[Player::left] * range);
  sf::Vector2i  movement(m_imovements[Player::right] + m_imovements[Player::up]);

  return (this->research(position, movement, origin, object, pos, &position.x));
}


bool
Searcher::lookAtRange(const sf::Vector2i& origin, int range,
		      unsigned char object, sf::Vector2u& pos)
{
  return (this->upToRight(origin, range, object, pos) ||
	  this->rightToDown(origin, range, object, pos) ||
	  this->downToLeft(origin, range, object, pos) ||
	  this->leftToUp(origin, range, object, pos));
}

bool
Searcher::search(const sf::Vector2i& origin, int range,
		 unsigned char object, sf::Vector2u& pos)
{
  int		i;
  bool		found;

  found = false;

  for (i = 1; i <= range && found == false; ++i)
    found = this->lookAtRange(origin, i, object, pos);

  return (found);
}


void
Searcher::execute(Player* player, const Action::UData& data)
{
  sf::Vector2u	pos;

  if (this->search(sf::Vector2i(player->getPosition().x, player->getPosition().y),
		   player->getClass()->getCharacteristicLevel(Class::perception),
		   data.id,
		   pos))
    player->vsend("OBJECT %d %d %d", data.id, pos.x, pos.y);
  else
    player->send("OBJECT NULL");
}
