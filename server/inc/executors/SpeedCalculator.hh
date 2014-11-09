//
// SpeedCalculator.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Nov  9 05:06:17 2014 
// Last Update Sun Nov  9 05:18:46 2014 
//

#ifndef SPEED_CALCULATOR_HH_
# define SPEED_CALCULATOR_HH_

# include "map/Hoopla.hh"

class		SpeedCalculator
{
private:
  unsigned int	m_speedCoefs[Hoopla::grounds_number];

public:
  SpeedCalculator();
  ~SpeedCalculator();

public:
  inline unsigned int	getSpeedCoef(unsigned char ground) const;
};

# include "SpeedCalculator.hpp"

#endif // !SPEED_CALCULATOR_HH_
