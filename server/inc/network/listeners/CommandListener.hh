//
// CommandListener.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Mon Nov  3 08:31:12 2014 
// Last Update Sat Nov  8 23:43:46 2014 
//

#ifndef COMMAND_LISTENER_HH_
# define COMMAND_LISTENER_HH_

# include "CommandCutter.hh"
# include "IListener.hh"
# include "network/Protocol.hh"

class			Client;

class			CommandListener : public IListener,
					  public CommandCutter
{
private:
  typedef bool	(CommandListener::*CommandExecution)(Client* client, char* const* args);

private:
  struct		Command
  {
    const char*		name;
    unsigned int	argsNumber;
    CommandExecution	execution;
  };

protected:
  Command		m_commands[MAX_COMMANDS_NUMBER];
  unsigned int		m_commandId;

public:
  CommandListener();
  virtual ~CommandListener();

protected:
  template <class T>
  void	initCommand(const char* name, unsigned int argsNumber,
		    bool (T::*command)(Client* client, char* const* args));

  template <class T>
  void	initCommand(const char* name, unsigned int argsNumber,
		    bool (T::*command)(Client* client, char* const* args) const);

protected:
  void	errorFromClient(const Client* client, const char* message, ...) const;

protected:
  virtual bool	executeCommand(CommandExecution execution, Client* client, char* const*args);
  virtual bool	unknowCommand(Client* client,
			      const CommandCutter::CuttedLine& cuttedCommand);

private:
  bool		tryToExecuteCommand(Client* client,
				    const CommandCutter::CuttedLine& cuttedCommand,
				    const Command& command);
  bool		searchAndExecuteCommand(Client* client,
					const CommandCutter::CuttedLine& command);

public:
  bool		listenFromClient(Client* client, char* message);
};

# include "CommandListener.hpp"

#endif // !COMMAND_LISTENER_HH_
