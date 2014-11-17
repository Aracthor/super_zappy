//
// ControlPanel.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Nov 16 16:43:03 2014 
// Last Update Mon Nov 17 13:24:22 2014 
//

#ifndef CONTROL_PANEL_HH_
# define CONTROL_PANEL_HH_

# include "LinkedToServer.hh"
# include "LogThread.hh"
# include "consoles/LogConsole.hh"
# include "ncursesxx/Application.hh"
# include "ncursesxx/Window.hh"

# define MAX_EVENT_CODE		(0x200)

# define CONSOLE_FRAMERATE	(60)

class	ControlPanel : public nc::Application,
		       private LinkedToServer
{
private:
  typedef void	(ControlPanel::*EventMethod)();

private:
  LogThread	m_logThread;
  LogConsole	m_logs;
  EventMethod	m_methods[MAX_EVENT_CODE];
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

private:
  void		manageDisplay() const;
  void		manageData();

private:
  void		catchInput();
  void		manageEvents();

public:
  void		run();
};

#endif // !CONTROL_PANEL_HH_
