//
// AttackTimeCalculator.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Tue Dec 16 08:53:56 2014 
// Last Update Tue Dec 16 08:55:11 2014 
//

#ifndef ATTACK_TIME_CALCULATOR_HH_
# define ATTACK_TIME_CALCULATOR_HH_

# include "ITimeCalculator.hh"
# include "catalogs/WeaponCatalog.hh"

class		AttackTimeCalculator : public ITimeCalculator
{
private:
  WeaponCatalog	m_catalog;

public:
  AttackTimeCalculator();
  ~AttackTimeCalculator();

public:
  unsigned int	calcTime(Player* player, const Action::UData& data);
};

#endif // !ATTACK_TIME_CALCULATOR_HH_
