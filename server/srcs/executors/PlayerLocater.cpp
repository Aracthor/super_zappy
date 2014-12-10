//
// PlayerLocater.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Tue Dec  9 13:07:38 2014 
// Last Update Tue Dec  9 13:43:31 2014 
//

#include "executors/PlayerLocater.hh"

PlayerLocater::PlayerLocater()
{
}

PlayerLocater::~PlayerLocater()
{
}


static int
checkDistance(const Player& player, const Player& ref)
{
  int	result;

  result = 0;

  if (player.getTeam() != ref.getTeam())
    {
      result = (ref.getClass()->getCharacteristicLevel(Class::perception) -
		DISTANCE(player.getPosition(), ref.getPosition()));
      if (result > 0 && ref.canSee(player.getPosition()) == false)
	result = 0;
    }

  return (result);
}

const Player*
PlayerLocater::locateClosestEnnemy(const Player* player) const
{
  return (this->getServerData()->findPlayer(&checkDistance, *player));
}

void
PlayerLocater::sendAnswer(Player* player, const Player* target) const
{
  if (target != NULL)
    player->vsend("PLAYER %s %d %d", target->getName(), target->getPosition().x, target->getPosition().y);
  else
    player->send("PLAYER NULL");
}


void
PlayerLocater::execute(Player* player, const Action::UData& data)
{
  const Player*	target;

  target = NULL;
  if (data.text[0] != '\0')
    target = this->getServerData()->getPlayer(data.text);

  if (target == NULL)
    target = this->locateClosestEnnemy(player);

  if (target != NULL && player->canSee(player->getPosition()) == false)
    target = NULL;
    

  this->sendAnswer(player, target);
}
