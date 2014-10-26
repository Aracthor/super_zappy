//
// GroundGenerator.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Wed Oct 22 14:31:07 2014 
// Last Update Sun Oct 26 01:18:12 2014 
//

#ifndef GROUND_GENERATOR_HH_
# define GROUND_GENERATOR_HH_

# include "map/Hoopla.hh"

class			GroundGenerator
{
private:
  Hoopla::EGround	m_grounds[MAX_HEIGHT + 1][MAX_MOISTURE + 1];

public:
  GroundGenerator();
  virtual ~GroundGenerator();

private:
  int			getHeightLevel(int height) const;
  int			getMoistureLevel(int moisture) const;
  Hoopla::EGround	getGround(int heightLevel, int moistureLevel) const;

public:
  void	setGrounds(Hoopla* hooplas, unsigned int number) const;

private:
  void  readGroundsConfigs();
};

# include "GroundGenerator.hpp"

#endif // !GROUND_GENERATOR_HH_
