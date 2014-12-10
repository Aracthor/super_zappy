//
// Equipement.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Tue Dec  9 14:36:29 2014 
// Last Update Tue Dec  9 14:49:06 2014 
//

#include "data/Equipement.hh"

Equipement::Equipement(Hoopla::EItem item) :
  m_item(item)
{
}

Equipement::~Equipement()
{
}


bool
Equipement::isWeapon() const
{
  return (false);
}
