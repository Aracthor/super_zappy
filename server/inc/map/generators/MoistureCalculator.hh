//
// MoistureCalculator.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Tue Oct 28 13:57:58 2014 
// Last Update Tue Oct 28 14:55:20 2014 
//

#ifndef MOISTURE_CALCULATOR_HH_
# define MOISTURE_CALCULATOR_HH_

# include "map/Hoopla.hh"

# define MOISTURE_RANGE	(50.0f)

# define IS_MOISTER_GROUND(ground)	(ground == Hoopla::river || ground == Hoopla::lake || ground == Hoopla::ice)

class	MoistureCalculator
{
private:
  float	m_moistureBonus[Hoopla::grounds_number];
  int	m_width;
  int	m_height;

public:
  MoistureCalculator(unsigned int width, unsigned int height);
  virtual ~MoistureCalculator();

private:
  float	calcDistance(int x1, int y1, int x2, int y2) const;
  void	addMoistureFromHoopla(const Hoopla* hoopla, float* moistures,
			      int x, int y);

public:
  void	calcMoistures(const Hoopla* hooplas, float* moistures);
};

#endif // !MOISTURE_CALCULATOR_HH_
