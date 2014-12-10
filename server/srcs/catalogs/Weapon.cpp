//
// Weapon.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Tue Dec  9 14:10:31 2014 
// Last Update Tue Dec  9 14:43:29 2014 
//

#include "catalogs/WeaponPlan.hh"

WeaponPlan::WeaponPlan() :
  ReadableFromZCSV("weapons.zcsv")
{
}

WeaponPlan::~WeaponPlan()
{
}


unsigned int
WeaponPlan::readFromString(const std::string& string, unsigned int pos)
{
  pos = this->read(string, pos, m_damages);
  pos = this->read(string, pos, m_ammo);
  if (m_ammo != Hoopla::none)
    pos = this->read(string, pos, m_reloadTime);

  return (pos);
}
