//
// DestroyerTimeCalculator.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Thu Nov 13 17:01:21 2014 
// Last Update Fri Nov 14 10:21:35 2014 
//

#ifndef DESTROYER_TIME_CALCULATOR_HH_
# define DESTROYER_TIME_CALCULATOR_HH_

# include "ITimeCalculator.hh"

class	DestroyerTimeCalculator : public ITimeCalculator
{
public:
  DestroyerTimeCalculator();
  ~DestroyerTimeCalculator();

public:
  unsigned int	calcTime(Player* player, const Action::UData& data);
};

#endif // !DESTROYER_TIME_CALCULATOR_HH_
