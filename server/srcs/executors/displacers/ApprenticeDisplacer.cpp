//
// ApprenticeDisplacer.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Nov  9 01:16:57 2014 
// Last Update Fri Nov 14 09:21:33 2014 
//

#include "abstractions/maths.hh"
#include "core/Server.hh"
#include "debug/LogManager.hh"
#include "executors/displacers/ApprenticeDisplacer.hh"

ApprenticeDisplacer::ApprenticeDisplacer()
{
}

ApprenticeDisplacer::~ApprenticeDisplacer()
{
}


bool
ApprenticeDisplacer::tryHorizontalMovement(const sf::Vector2u& pos, const sf::Vector2u& dest)
{
  bool	found;

  found = false;
  if (static_cast<int>(pos.x - dest.x) < 0)
    found = this->tryToJoin(pos + m_movements.getMovement(Player::right), dest, false);
  else if (static_cast<int>(pos.x - dest.x) > 0)
    found = this->tryToJoin(pos + m_movements.getMovement(Player::left), dest, false);

  return (found);
}

bool
ApprenticeDisplacer::tryVerticalMovement(const sf::Vector2u& pos, const sf::Vector2u& dest)
{
  bool	found;

  found = false;
  if (static_cast<int>(pos.y - dest.y) < 0)
    found = this->tryToJoin(pos + m_movements.getMovement(Player::down), dest, false);
  else if (static_cast<int>(pos.y - dest.y) > 0)
    found = this->tryToJoin(pos + m_movements.getMovement(Player::up), dest, false);

  return (found);
}

bool
ApprenticeDisplacer::tryNextPoint(const sf::Vector2u& pos, const sf::Vector2u& dest)
{
  bool		found;

  found = this->tryHorizontalMovement(pos, dest);
  if (found == false)
    found = this->tryVerticalMovement(pos, dest);

  return (found);
}

bool
ApprenticeDisplacer::tryToJoin(const sf::Vector2u& pos, const sf::Vector2u& dest, bool first)
{
  bool	found;

  if (pos == dest)
    {
      m_positions.pushBack(pos);
      found = true;
    }

  else
    {
      found = first || IS_EMPTY(this->getServerData()->getHoopla(pos));
      if (found)
	{
	  m_positions.pushBack(pos);
	  found = this->tryNextPoint(pos, dest);
	  if (found == false)
	    m_positions.popBack();
	}
    }

  return (found);
}


bool
ApprenticeDisplacer::search(const sf::Vector2u& origin, const sf::Vector2u& dest)
{
  bool	valid;

  valid = ((ABS(origin.x - dest.x) + ABS(origin.y - dest.y)) < DISPLACEMENT_MAX_LONGER);
  if (valid)
    {
      m_positions.clear();
      valid = this->tryToJoin(origin, dest, true);
    }

  return (valid);
}
