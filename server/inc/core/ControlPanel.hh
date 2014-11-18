//
// ControlPanel.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Nov 16 16:43:03 2014 
// Last Update Tue Nov 18 08:52:20 2014 
//

#ifndef CONTROL_PANEL_HH_
# define CONTROL_PANEL_HH_

# include "CommandExecuter.hh"
# include "LinkedToServer.hh"
# include "abstractions/Clock.hh"
# include "consoles/LogConsole.hh"
# include "consoles/PromptConsole.hh"
# include "ncursesxx/Application.hh"
# include "ncursesxx/Window.hh"

# define MAX_EVENT_CODE		(0x200)

# define CONSOLE_FRAMERATE	(60)

class		ControlPanel : public nc::Application,
			       public CommandExecuter
{
private:
  typedef void	(ControlPanel::*EventMethod)();

private:
  Clock		m_clock;
  LogConsole	m_logs;
  PromptConsole	m_prompt;
  EventMethod	m_methods[MAX_EVENT_CODE];
  long		m_remainingTime;
  bool		m_loop;

public:
  ControlPanel();
  ~ControlPanel();

private:
  EventMethod	getHandler(nc::Window::Event event) const;

  // Event handlers
private:
  void		exit();
  void		resize();
  void		incrementIndex();
  void		decrementIndex();
  void		deleteCharFromPrompt();
  void		confirmCommand();

private:
  bool		manageData();
  void		manageDisplay() const;

private:
  void		catchInput();
  void		manageEvents();

public:
  void		run();
};

#endif // !CONTROL_PANEL_HH_
