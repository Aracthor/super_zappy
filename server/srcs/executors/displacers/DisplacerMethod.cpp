//
// DisplacerMethod.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Nov  9 01:32:57 2014 
// Last Update Sun Nov  9 09:09:53 2014 
//

#include "core/Server.hh"
#include "executors/displacers/DisplacerMethod.hh"

DisplacerMethod::DisplacerMethod() :
  m_positions(DISPLACEMENT_MAX_LONGER)
{
  m_rotations[0] = sf::Vector2u( 1,  0);
  m_rotations[1] = sf::Vector2u( 0,  1);
  m_rotations[2] = sf::Vector2u(-1,  0);
  m_rotations[3] = sf::Vector2u( 0, -1);
}

DisplacerMethod::~DisplacerMethod()
{
}


int
DisplacerMethod::turn(Player* player, int orientation, int nextOrientation)
{
  Action::UData	data;

  if (nextOrientation - orientation == -1 || nextOrientation - orientation == 3)
    {
      data.id = -1;
      this->getServerData()->insertAction(Action(player, Action::rotate, 1, data));
      orientation -= 1;
      if (orientation == -1)
	orientation += 4;
    }

  else
    {
      data.id = 1;
      this->getServerData()->insertAction(Action(player, Action::rotate, 1, data));
      orientation += 1;
      if (orientation == 4)
	orientation -= 4;
    }

  return (orientation);
}

int
DisplacerMethod::calcNextOrientation(const sf::Vector2u& pos1,
				     const sf::Vector2u& pos2) const
{
  sf::Vector2u	rotation = pos2 - pos1;
  int		i;

  i = 0;
  while (m_rotations[i] != rotation)
    ++i;

  return (i);
}

bool
DisplacerMethod::isLast(unsigned int index) const
{
  bool	last;

  if (IS_EMPTY(this->getServerData()->getHoopla(m_positions.back())))
    last = (index == m_positions.getSize() - 2);
  else
    last = (index == m_positions.getSize() - 3);

  return (last);
}


void
DisplacerMethod::confirmMovement(Player* player)
{
  unsigned char	ground;
  unsigned int	index;
  unsigned int	time;
  int		nextOrientation;
  int		orientation;
  bool		last;

  index = 0;
  orientation = player->getOrientation();
  last = false;

  while (last == false)
    {
      nextOrientation = this->calcNextOrientation(m_positions[index],
						  m_positions[index + 1]);
      if (orientation != nextOrientation)
	orientation = this->turn(player, orientation, nextOrientation);
      else
	{
	  ground = this->getServerData()->getHoopla(m_positions[index]).ground;
	  time = m_speedCalculator.getSpeedCoef(ground) * player->getSpeedCoef() / 10;
	  last = this->isLast(index);
	  this->getServerData()->insertAction(Action(player, Action::move, time, last));
	  ++index;
	}
    }
}
