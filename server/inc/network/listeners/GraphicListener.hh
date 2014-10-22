//
// GraphicListener.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Mon Oct 20 14:20:41 2014 
// Last Update Wed Oct 22 12:21:53 2014 
//

#ifndef GRAPHIC_LISTENER_HH_
# define GRAPHIC_LISTENER_HH_

# include "CommandCutter.hh"
# include "GraphicMessages.hh"
# include "IListener.hh"

class			GraphicListener : public IListener,
					  public CommandCutter,
					  public GraphicMessages
{
private:
  struct		Command
  {
    const char*		name;
    unsigned int	argsNumber;
    CommandExecution	execution;
  };

private:
  Command	m_commands[GRAPHIC_COMMANDS_NUMBER];

public:
  GraphicListener();
  ~GraphicListener();

private:
  void	initCommand(unsigned int id,
		    const char* name, unsigned int argsNumber, CommandExecution execution);

private:
  bool	executeCommand(Client* client, const CommandCutter::CuttedLine& cuttedCommand,
		       const Command& command);
  bool	searchAndExecuteCommand(Client* client, const CommandCutter::CuttedLine& command);

public:
  bool	listenFromClient(Client* client, char* message);
};

#endif // !GRAPHIC_LISTENER_HH_
