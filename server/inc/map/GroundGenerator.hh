//
// GroundGenerator.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Wed Oct 22 14:31:07 2014 
// Last Update Wed Oct 22 14:35:58 2014 
//

#ifndef GROUND_GENERATOR_HH_
# define GROUND_GENERATOR_HH_

# include "Hoopla.hh"

class	GroundGenerator
{
private:
  Hoopla::EGround	m_grounds[MAX_HEIGHT][MAX_MOISTURE];

public:
  GroundGenerator();
  virtual ~GroundGenerator();

private:
  void  readGroundsConfigs();

public:
  inline Hoopla::EGround	getGroundFromEnvironnement(unsigned int height,
							   unsigned int moisture) const;
};

# include "GroundGenerator.hpp"

#endif // !GROUND_GENERATOR_HH_
