//
// HeightGenerator.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Mon Nov  3 14:45:42 2014 
// Last Update Mon Nov  3 15:46:37 2014 
//

#ifndef HEIGHT_GENERATOR_HH_
# define HEIGHT_GENERATOR_HH_

# include "map/Hoopla.hh"

class	HeightGenerator
{
public:
  HeightGenerator();
  virtual ~HeightGenerator();

public:
  void	calcHeights(Hoopla* hooplas, unsigned int width, unsigned int height);
};

#endif // !HEIGHT_GENERATOR_HH_
