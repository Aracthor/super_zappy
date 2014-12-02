//
// ControlPanel.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Nov 16 16:43:03 2014 
// Last Update Thu Nov 20 13:36:17 2014 
//

#ifndef CONTROL_PANEL_HH_
# define CONTROL_PANEL_HH_

# include "CommandExecuter.hh"
# include "LinkedToServer.hh"
# include "LogThread.hh"
# include "consoles/DataConsole.hh"
# include "consoles/LogConsole.hh"
# include "consoles/PromptConsole.hh"
# include "ncursesxx/Application.hh"
# include "ncursesxx/Window.hh"
# include "threading/Mutex.hh"

# define MAX_EVENT_CODE		(0x230)

# define CONSOLE_FRAMERATE	(60)

# define MIN_CONSOLE_WIDTH	(30)
# define MIN_CONSOLE_HEIGHT	(5)

class		ControlPanel : public nc::Application,
			       public CommandExecuter
{
private:
  typedef void	(ControlPanel::*EventMethod)();
  typedef void	(ControlPanel::*DataConsoleMethod)(Console* dataConsole) const;

private:
  LogThread	m_logThread;
  Mutex		m_mutex;
  Console*	m_dataConsoles[DATA_CONSOLES_NUMBER];
  LogConsole	m_logs;
  PromptConsole	m_prompt;
  EventMethod	m_methods[MAX_EVENT_CODE];
  long		m_remainingTime;
  unsigned int	m_dataIndex;
  bool		m_loop;

public:
  ControlPanel();
  ~ControlPanel();

private:
  EventMethod	getHandler(nc::Window::Event event) const;

private:
  void		doToDataConsoles(DataConsoleMethod method) const;
  void		resizeDataConsole(Console* dataConsole) const;

  // Event handlers
private:
  void		exit();
  void		resize();
  void		incrementIndex();
  void		decrementIndex();
  void		incrementConsoleIndex();
  void		decrementConsoleIndex();
  void		deleteCharFromPrompt();
  void		confirmCommand();

private:
  void		manageData();
  void		manageDisplay() const;
  void		manageEvents();

public:
  void		update();
  void		run();
};

#endif // !CONTROL_PANEL_HH_
