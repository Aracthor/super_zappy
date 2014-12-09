//
// IAListener.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Mon Oct 20 14:27:00 2014 
// Last Update Thu Dec  4 09:25:57 2014 
//

#include "core/Server.hh"
#include "data/Class.hh"
#include "debug/LogManager.hh"
#include "debug/usefull.hh"
#include "network/listeners/TeamListener.hh"

#include <cstdlib>

TeamListener::TeamListener()
{
  this->initCommand("PRE", 7, &TeamListener::getTeamPresentation);
  this->initCommand("CLD", 2 + Class::characteristics_number + Class::skills_number,
		    &TeamListener::getClassPresentation);
  this->initCommand("PLD", 3, &TeamListener::getPlayerPresentation);
}

TeamListener::~TeamListener()
{
}


void
TeamListener::warnCheat(const Client* client, const char* cheat)
{
  LogManagerSingleton::access()->error->print("Client %d tried to cheat : %s !!!",
					      client->getFd(), cheat);
  this->getServerData()->vsayToGraphicClients("CHT %s %s\n", client->getTeam()->getName(), cheat);
}


bool
TeamListener::getClassPresentation(Client* client, char* const* args, Team* team)
{
  const char*	error;
  bool		valid;

  error = team->addClass(args[1],
			 atoi(args[2]), atoi(args[3]),
			 atoi(args[4]), atoi(args[5]), atoi(args[6]),
			 atoi(args[7]), atoi(args[8]), atoi(args[9]), atoi(args[10]));
  valid = (error == NULL);
  if (valid == false)
    this->warnCheat(client, error);

  return (valid);
}

bool
TeamListener::getPlayerPresentation(Client* client, char* const* args, Team* team)
{
  bool	valid;

  valid = team->addPlayer(args[1], args[2]);

  if (valid)
    {
      *client << args[1] << ' ' << "START " << this->getServerData()->isStarted() << '\n';
      this->getServerData()->sayToGraphicClients(team->getLastPlayer());
    }

  return (valid);
}


bool
TeamListener::executeTeamCommand(Client* client, char* const* args,
				 TeamCommandExecution execution)
{
  Team*	team;
  bool	valid;

  team = client->getTeam();
  valid = (team != NULL);

  if (valid == true)
    valid = (this->*execution)(client, args, team);

  return (valid);
}


bool
TeamListener::executeUnknowCommand(Player* player, const CommandCutter::CuttedLine& cuttedCommand)
{
  Action			action;
  CommandCutter::CuttedLine	args;
  unsigned int			i;
  bool				valid;

  args.argsNumber = cuttedCommand.argsNumber - 2;
  for (i = 0; i < cuttedCommand.argsNumber - 2; ++i)
    args.args[i] = const_cast<char*>(cuttedCommand.args[i + 2]);

  valid = this->createAction(action, cuttedCommand.args[0], player, args);
  if (valid && action.getTimer() > 0)
    this->getServerData()->insertAction(action);

  return (valid);
}

bool
TeamListener::unknowCommand(Client* client,
			    const CommandCutter::CuttedLine& cuttedCommand)
{
  Player*	player;
  bool		valid;

  valid = (cuttedCommand.argsNumber >= 2);
  if (valid)
    {
      player = this->getServerData()->getPlayerFromName(cuttedCommand.args[1]);
      valid = (player != NULL);
      valid = (checkOrPrint(player != NULL, "Unknow player %s", cuttedCommand.args[1]) &&
	       checkOrPrint(player->getTeam() == client->getTeam(), "Client %d is not client of player %s",
			    client->getFd(), cuttedCommand.args[1]));
      if (valid)
	valid = this->executeUnknowCommand(player, cuttedCommand);
    }

  return (valid);
}


bool
TeamListener::getTeamPresentation(Client* client, char* const* args)
{
  Team*		team;
  const char*	error;
  bool		valid;

  team = this->getServerData()->getTeamFromName(args[1]);
  if ((valid = (team != NULL)) == false)
    this->errorFromClient(client, "Invalid team name %s.", args[1]);
  else if ((valid = !team->hasReadyConfig()) == false)
    this->errorFromClient(client, "Team %s already configured.", args[1]);

  else
    {
      error = team->setConfigs(atoi(args[2]), atoi(args[3]),
			       atoi(args[4]), atoi(args[5]), atoi(args[6]));
      team->setClient(client);
      valid = (error == NULL);
      if (valid == false)
	this->errorFromClient(client, "Error with configs : %s.", error);
      else
	client->giveTeam(team);
    }

  return (valid);
}

bool
TeamListener::getClassPresentation(Client* client, char* const* args)
{
  return (this->executeTeamCommand(client, args, &TeamListener::getClassPresentation));
}

bool
TeamListener::getPlayerPresentation(Client* client, char* const* args)
{
  return (this->executeTeamCommand(client, args, &TeamListener::getPlayerPresentation));
}
