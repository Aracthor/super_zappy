//
// Player.hpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Thu Nov  6 18:16:49 2014 
// Last Update Wed Dec 10 11:27:14 2014 
//

#include "map/Map.hh"

const Team*
Player::getTeam() const
{
  return (m_team);
}

const Class*
Player::getClass() const
{
  return (m_class);
}

const sf::Vector2u&
Player::getPosition() const
{
  return (m_position);
}

Player::EOrientation
Player::getOrientation() const
{
  return (m_orientation);
}

const Equipement*
Player::getEquipement() const
{
  return (m_equipement);
}

Hoopla::EItem
Player::getEquipementItem() const
{
  return (m_equipement ? m_equipement->getItem() : Hoopla::none);
}

const Inventory&
Player::getInventory() const
{
  return (m_inventory);
}

Inventory&
Player::getInventory()
{
  return (m_inventory);
}

const Action::UData&
Player::getObjective() const
{
  return (m_currentObjective);
}

bool
Player::isDecremented() const
{
  return (m_decremented);
}


unsigned int
Player::getSpeedCoef() const
{
  return (m_class->getSkillLevel(Class::speed) == 1 ? 15 :
	  m_class->getSkillLevel(Class::speed) == 2 ? 12 :
	  m_class->getSkillLevel(Class::speed) == 3 ? 10 : 8);
}


void
Player::setDecremented(bool decremented)
{
  m_decremented = decremented;
}
