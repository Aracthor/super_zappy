//
// Weapon.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Tue Dec  9 14:09:38 2014 
// Last Update Tue Dec  9 16:12:33 2014 
//

#ifndef WEAPON_PLAN_HH_
# define WEAPON_PLAN_HH_

# include "ReadableFromZCSV.hh"

class		WeaponPlan : public ReadableFromZCSV
{
private:
  unsigned int	m_damages;
  unsigned int	m_range;
  Hoopla::EItem	m_ammo;
  unsigned int	m_reloadTime;

public:
  WeaponPlan();
  ~WeaponPlan();

public:
  unsigned int	readFromString(const std::string& string, unsigned int pos);

public:
  inline unsigned int	getDamages() const;
  inline unsigned int	getRange() const;
  inline Hoopla::EItem	getAmmo() const;
  inline unsigned int	getReloadTime() const;
};

# include "WeaponPlan.hpp"

#endif // !WEAPON_PLAN_HH_
