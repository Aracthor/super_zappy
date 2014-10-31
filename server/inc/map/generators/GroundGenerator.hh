//
// GroundGenerator.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Wed Oct 22 14:31:07 2014 
// Last Update Tue Oct 28 14:01:24 2014 
//

#ifndef GROUND_GENERATOR_HH_
# define GROUND_GENERATOR_HH_

# include "map/Hoopla.hh"

# define LAKE_GROUND(height)	(height / 10.0f < COLD_HEIGHT ? Hoopla::lake : Hoopla::ice)

class			GroundGenerator
{
private:
  Hoopla::EGround	m_grounds[MAX_HEIGHT + 1][MAX_MOISTURE + 1];

public:
  GroundGenerator();
  virtual ~GroundGenerator();

private:
  float			getHeightLevel(float height) const;
  float			getMoistureLevel(float moisture) const;
  Hoopla::EGround	getGround(float heightLevel, float moistureLevel) const;

public:
  void	setDefaultGrounds(Hoopla* hooplas, unsigned int number) const;
  void	setGrounds(Hoopla* hooplas, float* moistures, unsigned int number) const;

private:
  void  readGroundsConfigs();
};

# include "GroundGenerator.hpp"

#endif // !GROUND_GENERATOR_HH_
