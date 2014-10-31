//
// RiverGenerator.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Mon Oct 27 17:15:05 2014 
// Last Update Mon Oct 27 18:05:27 2014 
//

#ifndef RIVER_GENERATOR_HH_
# define RIVER_GENERATOR_HH_

# include "AGenerator.hh"

# define RIVER_CHANCES		(100)

# define RIVER_HEIGHT_LOSS	(2)
# define MAX_LAKE_DEPTH		(10)

class		RiverGenerator : public virtual AGenerator
{
public:
  RiverGenerator(unsigned int width, unsigned int height);
  virtual ~RiverGenerator();

private:
  Position	m_movements[4];

private:
  inline bool	        canHandleRiver(const Hoopla& hoopla) const;

private:
  bool	extendLake(Position& position, float height);
  bool  createLake(Position& position);
  bool  findSlope(Position& position);

public:
  void	createRiver(const Position& position);
};

# include "RiverGenerator.hpp"

#endif // !RIVER_GENERATOR_HH_
