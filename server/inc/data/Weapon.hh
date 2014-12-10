//
// Weapon.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Tue Dec  9 14:47:55 2014 
// Last Update Wed Dec 10 10:24:36 2014 
//

#ifndef WEAPON_HH_
# define WEAPON_HH_

# include "Equipement.hh"
# include "Player.hh"
# include "catalogs/WeaponPlan.hh"

class		Weapon : public Equipement
{
private:
  unsigned int	m_damages;
  unsigned int	m_range;

public:
  Weapon(Hoopla::EItem item, const WeaponPlan& plan);
  virtual ~Weapon();

public:
  virtual Hoopla::EItem	getProjectile() const;
  virtual bool		canFire() const;
  virtual void		onUse(Player* owner) const;
  bool			isWeapon() const;

public:
  inline unsigned int	getDamages() const;
  inline unsigned int	getRange() const;
};

# include "Weapon.hpp"

#endif // !WEAPON_HH_
