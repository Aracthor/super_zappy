//
// IAListener.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Mon Oct 20 14:27:00 2014 
// Last Update Sun Nov  9 04:06:17 2014 
//

#include "core/Server.hh"
#include "data/Class.hh"
#include "debug/LogManager.hh"
#include "network/listeners/TeamListener.hh"

#include <cstdlib>

TeamListener::TeamListener()
{
  this->initCommand("PRE", 7, &TeamListener::getTeamPresentation);
  this->initCommand("CLD", 2 + CHARACTERISTICS_NUMBER + SKILLS_NUMBER,
		    &TeamListener::getClassPresentation);
  this->initCommand("PLD", 3, &TeamListener::getPlayerPresentation);
}

TeamListener::~TeamListener()
{
}


void
TeamListener::warnCheat(const Client* client, const char* cheat) const
{
  LogManagerSingleton::access()->error.print("Client %d tried to cheat : %s !!!",
					     client->getFd(), cheat);
  // TODO prévenir les graphiques
}


bool
TeamListener::getClassPresentation(Client* client, char* const* args, Team* team)
{
  const char*	error;
  bool		valid;

  error = team->addClass(args[1],
			 atoi(args[2]), atoi(args[3]),
			 atoi(args[4]), atoi(args[5]), atoi(args[6]),
			 atoi(args[7]), atoi(args[8]));
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
TeamListener::unknowCommand(Client* client,
			    const CommandCutter::CuttedLine& cuttedCommand)
{
  CommandCutter::CuttedLine	args;
  Action			action;
  Player*			player;
  unsigned int			i;
  bool				valid;

  (void)(client); // TODO check if player is member of this client team
  valid = (cuttedCommand.argsNumber >= 2);
  if (valid)
    {
      player = this->getServerData()->getPlayerFromName(cuttedCommand.args[1]);
      valid = (player != NULL);
      if (valid)
	{
	  args.argsNumber = cuttedCommand.argsNumber - 2;
	  for (i = 0; i < cuttedCommand.argsNumber - 2; ++i)
	    args.args[i] = const_cast<char*>(cuttedCommand.args[i + 2]);

	  valid = this->createAction(action, cuttedCommand.args[0], player, args);
	  if (valid)
	    this->getServerData()->insertAction(action);
	}
      else
	LogManagerSingleton::access()->error.print("Unknow player %s", args.args[1]);
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
