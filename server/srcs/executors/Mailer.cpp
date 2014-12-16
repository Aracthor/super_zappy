//
// Mailer.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Fri Nov 14 14:43:23 2014 
// Last Update Thu Dec 11 13:32:43 2014 
//

#include "abstractions/maths.hh"
#include "core/Server.hh"
#include "executors/Mailer.hh"

Mailer::Mailer()
{
}

Mailer::~Mailer()
{
}


static void	sendMail(Player& dest, const Player& from, const char* message)
{
  if (dest.getName() != from.getName() &&
      dest.getTeam() == from.getTeam() &&
      DISTANCE(dest.getPosition(), from.getPosition()) <
      dest.getClass()->getCharacteristicLevel(Class::perception))
    dest.vsend("%s %s %s", MAIL_MESSAGE, from.getName(), message);
}

void
Mailer::execute(Player* player, const Action::UData& data)
{
  this->getServerData()->vsayToGraphicClients("MSG %s %s\n", player->getName(), data.text);
  this->getServerData()->doToPlayers(&sendMail, *player, data.text);
}
