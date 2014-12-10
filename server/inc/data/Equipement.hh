//
// Equipement.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Tue Dec  9 14:36:25 2014 
// Last Update Tue Dec  9 14:49:01 2014 
//

#ifndef EQUIPEMENT_HH_
# define EQUIPEMENT_HH_

# include "map/Hoopla.hh"

class			Equipement
{
protected:
  const Hoopla::EItem	m_item;

public:
  Equipement(Hoopla::EItem item);
  virtual ~Equipement();

public:
  virtual bool	isWeapon() const;

public:
  inline Hoopla::EItem	getItem() const;
};

# include "Equipement.hpp"

#endif // !EQUIPEMENT_HH_
