//
// ITimeCalculator.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Thu Nov 13 16:52:25 2014 
// Last Update Fri Nov 14 17:30:12 2014 
//

#ifndef ITIME_CALCULATOR_HH_
# define ITIME_CALCULATOR_HH_

# include "actions/Action.hh"
# include "core/LinkedToServer.hh"
# include "data/Player.hh"

class	ITimeCalculator : protected LinkedToServer
{
public:
  virtual ~ITimeCalculator() {}

public:
  virtual unsigned int	calcTime(Player* player, const Action::UData& data) = 0;
};

#endif // !ITIME_CALCULATOR_HH_
