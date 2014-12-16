//
// CraftTimeCalculator.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Fri Nov 14 10:17:13 2014 
// Last Update Tue Dec 16 08:55:07 2014 
//

#ifndef CRAFT_TIME_CALCULATOR_HH_
# define CRAFT_TIME_CALCULATOR_HH_

# include "ITimeCalculator.hh"
# include "catalogs/CraftCatalog.hh"

class		CraftTimeCalculator : public ITimeCalculator
{
private:
  CraftCatalog	m_catalog;

public:
  CraftTimeCalculator();
  ~CraftTimeCalculator();

private:
  bool		checkRequires(const Player* player, const unsigned int* requires) const;
  bool		checkPlaceForProduce(const Player* player, Hoopla::EItem item) const;
  bool		checkCapacity(const Player* player, Hoopla::EItem item) const;

public:
  unsigned int	calcTime(Player* player, const Action::UData& data);
};

#endif // !CRAFT_TIME_CALCULATOR_HH_
