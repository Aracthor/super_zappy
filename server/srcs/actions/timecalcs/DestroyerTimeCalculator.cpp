//
// DestroyerTimeCalculator.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Thu Nov 13 17:01:24 2014 
// Last Update Thu Dec  4 10:48:05 2014 
//

#include "actions/timecalcs/DestroyerTimeCalculator.hh"
#include "core/Server.hh"

DestroyerTimeCalculator::DestroyerTimeCalculator()
{
}

DestroyerTimeCalculator::~DestroyerTimeCalculator()
{
}


void
DestroyerTimeCalculator::turnFaceToCoord(Player* player, const sf::Vector2u& coord)
{
  Action::UData	data;
  sf::Vector2u	position;
  unsigned int	distance;

  distance = DISTANCE(position, coord);
  if (distance == 2)
    {
      data.id = 1;
      this->getServerData()->insertAction(Action(player, Action::rotate, 1, data));
      this->getServerData()->insertAction(Action(player, Action::rotate, 1, data));
    }

  else if (distance == 1)
    {
      if (position + m_movements.getMovement(Player::right) == coord)
	data.id = 1;
      else
	data.id = -1;
      this->getServerData()->insertAction(Action(player, Action::rotate, 1, data));
    }
}

bool
DestroyerTimeCalculator::getHoopla(Player* player, Hoopla** hoopla, const sf::Vector2u& coord)
{
  bool  valid;

  valid = (DISTANCE(player->getPosition(), coord) == 1);

  if (valid)
    {
      this->turnFaceToCoord(player, coord);
      *hoopla = &this->getServerData()->getHoopla(coord);
    }

  return (valid);
}


unsigned int
DestroyerTimeCalculator::calcTime(Player* player, const Action::UData& data)
{
  Hoopla*	hoopla;
  unsigned int	time;

  time = 0;
  if (this->getHoopla(player, &hoopla, sf::Vector2u(data.position.x, data.position.y)) == true)
    {
      time = m_catalog[hoopla->object].getDestroyTime();
      if (m_catalog[hoopla->object].isDestroyable() == false)
	time = 0;
      (void)player;	// TODO mutliplicator with player equipement
    }

  if (time == 0)
    player->send("END FALSE");

  return (time);
}
