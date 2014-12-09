//
// TeamListener.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Mon Oct 20 14:20:41 2014 
// Last Update Thu Dec  4 09:12:16 2014 
//

#ifndef TEAM_LISTENER_HH_
# define TEAM_LISTENER_HH_

# include "CommandListener.hh"
# include "actions/ActionFactory.hh"
# include "data/Team.hh"

class	TeamListener : public CommandListener,
		       private ActionFactory
{
private:
  typedef bool	(TeamListener::*TeamCommandExecution)(Client* client,
						      char* const* args, Team* team);

public:
  TeamListener();
  ~TeamListener();

private:
  void	warnCheat(const Client* client, const char* cheat);

private:
  bool	getClassPresentation(Client* client, char* const* args, Team* team);
  bool	getPlayerPresentation(Client* client, char* const* args, Team* team);

private:
  bool	executeTeamCommand(Client* client, char* const* args,TeamCommandExecution execution);

private:
  bool	executeUnknowCommand(Player* player, const CommandCutter::CuttedLine& cuttedLine);
  bool	unknowCommand(Client* client,
		      const CommandCutter::CuttedLine& cuttedCommand);

private:
  bool	getTeamPresentation(Client* client, char* const* args);
  bool	getClassPresentation(Client* client, char* const* args);
  bool	getPlayerPresentation(Client* client, char* const* args);
};

#endif // !TEAM_LISTENER_HH_
