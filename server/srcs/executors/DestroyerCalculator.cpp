//
// DestroyerCalculator.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Nov  9 10:13:18 2014 
// Last Update Wed Nov 12 10:09:09 2014 
//

#include "executors/DestroyerCalculator.hh"

DestroyerCalculator::DestroyerCalculator()
{
}

DestroyerCalculator::~DestroyerCalculator()
{
}


int
DestroyerCalculator::calcTime(Player* player, unsigned char objectId)
{
  // TODO
  (void)(player);
  (void)(objectId);
  return (10);
}


void
DestroyerCalculator::execute(Player* player, const Action::UData& data)
{
  Action::UData	newData;
  int		time;
  unsigned char	objectId;

  objectId = this->getServerData()->getHoopla(data.position.x, data.position.y).object;
  time = this->calcTime(player, objectId);
  newData.id = objectId;

  if (time > 0)
    this->insertAction(Action(player, Action::destroy, time, newData));
  else
    player->send("END false\n");
}
