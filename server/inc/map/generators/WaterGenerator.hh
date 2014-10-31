//
// WaterGenerator.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Oct 26 10:24:48 2014 
// Last Update Tue Oct 28 19:48:10 2014 
//

#ifndef WATER_GENERATOR_HH_
# define WATER_GENERATOR_HH_

# include "LowLakeGenerator.hh"
# include "RiverGenerator.hh"

class		WaterGenerator : public RiverGenerator,
				 public LowLakeGenerator
{
public:
  WaterGenerator(unsigned int width, unsigned int height);
  virtual ~WaterGenerator();

public:
  void	insertWater(Hoopla* hooplas);
};

#endif // !WATER_GENERATOR_HH_
