//
// Weapon.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Tue Dec  9 14:48:08 2014 
// Last Update Wed Dec 10 10:49:05 2014 
//

#include "data/Weapon.hh"

Weapon::Weapon(Hoopla::EItem item, const WeaponPlan& plan) :
  Equipement(item),
  m_damages(plan.getDamages()),
  m_range(plan.getRange())
{
}

Weapon::~Weapon()
{
}


Hoopla::EItem
Weapon::getProjectile() const
{
  return (m_item);
}

bool
Weapon::canFire() const
{
  return (true);
}

void
Weapon::onUse(Player* player) const
{
  player->unequip();
}

bool
Weapon::isWeapon() const
{
  return (true);
}
