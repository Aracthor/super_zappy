//
// MoistureCalculator.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Tue Oct 28 14:03:38 2014 
// Last Update Tue Oct 28 14:59:41 2014 
//

#include "abstractions/maths.hh"
#include "map/generators/MoistureCalculator.hh"

#include <cstring>

MoistureCalculator::MoistureCalculator(unsigned int width, unsigned int height) :
  m_width(width),
  m_height(height)
{
  m_moistureBonus[Hoopla::river] = 0.05f;
  m_moistureBonus[Hoopla::lake] = 0.02f;
  m_moistureBonus[Hoopla::ice] = 0.01f;
}

MoistureCalculator::~MoistureCalculator()
{
}


float
MoistureCalculator::calcDistance(int x1, int y1, int x2, int y2) const
{
  float	x;
  float	y;

  x = ABS(x1 - x2);
  x *= x;
  y = ABS(y1 - y2);
  y *= y;

  return (sqrtf(x + y));
}

void
MoistureCalculator::addMoistureFromHoopla(const Hoopla* hoopla, float* moistures,
					  int posX, int posY)
{
  int	x, y;
  float	distance;

  for (x = posX - MOISTURE_RANGE; x < posX + MOISTURE_RANGE; ++x)
    for (y = posY - MOISTURE_RANGE; y < posY + MOISTURE_RANGE; ++y)
      if (x >= 0 && y >= 0 && x < m_width && y < m_height)
	{
	  distance = this->calcDistance(posX, posY, x, y) / MOISTURE_RANGE;

	  if (distance < 1.0f && distance > 0.0f)
	    moistures[y * m_width + x] += (m_moistureBonus[hoopla->ground]
					   / distance / distance);
	}
}


void
MoistureCalculator::calcMoistures(const Hoopla* hooplas, float* moistures)
{
  const Hoopla*	hoopla;
  int		x, y;

  memset(moistures, 0, m_width * m_height * sizeof(float));

  for (x = 0; x < m_width; ++x)
    for (y = 0; y < m_height; ++y)
      {
	hoopla = &hooplas[y * m_width + x];
	if (IS_MOISTER_GROUND(hoopla->ground))
	  this->addMoistureFromHoopla(hoopla, moistures, x, y);
      }
}
