//
// Player.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Tue Nov  4 08:48:47 2014 
// Last Update Thu Dec 11 14:45:01 2014 
//

#include "core/Server.hh"
#include "data/Player.hh"
#include "data/Team.hh"
#include "debug/LogManager.hh"

#include <cstdarg>
#include <cstdio>

Player::Player()
{
}

Player::Player(const char* name, const Team* team, const Class* refToClass) :
  Namable(name),
  Hurtable(refToClass->getMaxLife()),
  m_team(team),
  m_class(refToClass),
  m_position(this->getServerData()->getSpawnPoint(team->getSpawnPoint())),
  m_orientation(right),
  m_equipement(NULL),
  m_inventory(m_class->getInventorySize())
{
}

Player::~Player()
{
  if (m_equipement != NULL)
    delete (m_equipement);
}


void
Player::die()
{
  this->getServerData()->getHoopla(m_position).hasPlayer = false;
  this->getServerData()->vsayToGraphicClients("PDD %s\n", this->getName());
  this->send(DEAD_MESSAGE);
  LogManagerSingleton::access()->intern->print("Player %s die at %d/%d.",
					       this->getName(), m_position.x, m_position.y);
}

void
Player::hurt(unsigned int damages)
{
  LogManagerSingleton::access()->intern->print("Player %s get %d damages.", this->getName(), damages);
  Hurtable::hurt(damages);
  this->getServerData()->vsayToGraphicClients("PCL %s %d\n", this->getName(), m_currentLife);
  if (this->isDead())
    this->die();
}

void
Player::heal(unsigned int healing)
{
  LogManagerSingleton::access()->intern->print("Player %s heal %d damages.", this->getName(), healing);
  Hurtable::heal(healing);
  this->getServerData()->vsayToGraphicClients("PCL %s %d\n", this->getName(), m_currentLife);
}


void
Player::unequip()
{
  if (m_equipement != NULL)
    {
      delete (m_equipement);
      m_equipement = NULL;
      this->getServerData()->vsayToGraphicClients("PEQ %s 0\n", this->getName());
    }
}

void
Player::setEquipement(Equipement* equipement)
{
  m_equipement = equipement;
  this->getServerData()->vsayToGraphicClients("PEQ %s %d\n", this->getName(), equipement->getItem());
}

bool
Player::move()
{
  sf::Vector2u	newPos;
  bool		valid;

  newPos = m_position;

  if (m_orientation == right)
    ++newPos.x;
  else if (m_orientation == down)
    ++newPos.y;
  else if (m_orientation == left)
    --newPos.x;
  else if (m_orientation == up)
    --newPos.y;

  valid = IS_EMPTY(this->getServerData()->getHoopla(newPos));
  if (valid)
    {
      this->getServerData()->getHoopla(m_position).hasPlayer = false;
      m_position = newPos;
      this->getServerData()->getHoopla(m_position).hasPlayer = true;
    }

  return (valid);
}

void
Player::rotate(int rotation)
{
  m_orientation = static_cast<Player::EOrientation>(static_cast<int>(m_orientation) +
						    rotation);
  if (m_orientation == static_cast<Player::EOrientation>(-1))
    m_orientation = static_cast<Player::EOrientation>(3);
  else if (m_orientation == static_cast<Player::EOrientation>(4))
    m_orientation = static_cast<Player::EOrientation>(0);
}

void
Player::send(const char* message)
{
  *m_team->getClient() << this->getName() << ' ' << message << LINE_SEPARATOR;
}

void
Player::vsend(const char* message, ...)
{
  va_list	list;
  char		buffer[0x100];

  va_start(list, message);
  {
    vsprintf(buffer, message, list);
  }
  va_end(list);

  this->send(buffer);
}


bool
Player::canSee(const sf::Vector2u& pos) const
{
  bool	can;

  can = (DISTANCE(m_position, pos) <= m_class->getCharacteristicLevel(Class::perception));
  if (can)
    {
      // TODO check for walls
    }

  return (can);
}
