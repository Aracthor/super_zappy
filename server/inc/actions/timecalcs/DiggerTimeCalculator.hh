//
// DiggerTimeCalculator.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Fri Nov 14 16:52:10 2014 
// Last Update Fri Nov 14 17:23:43 2014 
//

#ifndef DIGGER_TIME_CALCULATOR_HH_
# define DIGGER_TIME_CALCULATOR_HH_

# include "ITimeCalculator.hh"
# include "catalogs/GroundCatalog.hh"
# include "map/Hoopla.hh"

class		DiggerTimeCalculator : public ITimeCalculator
{
public:
  GroundCatalog	m_catalog;

public:
  DiggerTimeCalculator();
  ~DiggerTimeCalculator();

public:
  unsigned int	calcTime(Player* player, const Action::UData& data);
};

#endif // !DIGGER_TIME_CALCULATOR_HH_
