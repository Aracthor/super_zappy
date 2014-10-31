//
// RiverGenerator.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Mon Oct 27 17:49:21 2014 
// Last Update Mon Oct 27 18:04:14 2014 
//

#include "map/generators/GroundGenerator.hh"
#include "map/generators/RiverGenerator.hh"

RiverGenerator::RiverGenerator(unsigned int width, unsigned int height) :
  AGenerator(width, height)
{
  m_movements[0] = Position(-1,  0);
  m_movements[1] = Position( 1,  0);
  m_movements[2] = Position( 0, -1);
  m_movements[3] = Position( 0,  1);
}

RiverGenerator::~RiverGenerator()
{
}

bool
RiverGenerator::extendLake(Position& position, float height)
{
  Hoopla&	hoopla = this->getHoopla(position);
  Position	initialPosition(position);
  Position	newPosition;
  float		slope;
  unsigned int	i;
  bool		open;

  hoopla.height = height;
  hoopla.ground = LAKE_GROUND(height);

  open = false;
  for (i = 0; i < 4; ++i)
    {
      newPosition = initialPosition + m_movements[i];
      slope = this->getHoopla(newPosition).height - height;
      if (slope < -1.0f)
	{
	  open = true;
	  position = newPosition;
	}
      else if (slope < 0.0f)
	{
	  open = this->extendLake(newPosition, height);
	  if (open)
	    position = newPosition;
	}
    }

  return (open);
}

bool
RiverGenerator::createLake(Position& position)
{
  float		height;
  unsigned int	i;
  bool		open;

  height = this->getHoopla(position).height;
  for (i = 0, open = false; i < MAX_LAKE_DEPTH && open == false; ++i)
    open = extendLake(position, height + i);

  return (open);
}

bool
RiverGenerator::findSlope(Position& position)
{
  const Hoopla&	hoopla = this->getHoopla(position);
  Position	newPosition;
  Position	futurePosition;
  unsigned int	i;
  float		bestSlope;
  float		slope;
  bool		found;

  bestSlope = 0.0f;

  found = false;
  if (position.x > 0 && position.y > 0 &&
      (unsigned int)position.x < m_width - 1 && (unsigned int)position.y < m_height - 1)
    for (i = 0; i < 4; ++i)
      {
	newPosition = position + m_movements[i];
	slope = this->getHoopla(newPosition).height - hoopla.height;
	if (slope < bestSlope)
	  {
	    futurePosition = newPosition;
	    bestSlope = slope;
	    found = true;
	  }
      }

  if (found)
    position = futurePosition;
  else
    found = this->createLake(position);

  return (found);
}


void
RiverGenerator::createRiver(const Position& position)
{
  Hoopla*	hoopla = &this->getHoopla(position);
  Position      newPosition(position);

  if (this->findSlope(newPosition) &&
      this->canHandleRiver(this->getHoopla(newPosition)))
    this->createRiver(newPosition);

  if (this->getHoopla(position).ground == Hoopla::ocean)
    {
      hoopla->height -= RIVER_HEIGHT_LOSS;
      hoopla->ground = Hoopla::river;
    }
}

