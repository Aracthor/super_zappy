//
// ControlPanel.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Nov 16 16:43:06 2014 
// Last Update Tue Nov 18 10:06:11 2014 
//

#include "core/ControlPanel.hh"

#include <cstring>
#include <sys/select.h>
#include <sys/time.h>
#include <unistd.h>

ControlPanel::ControlPanel() :
  m_remainingTime(0)
{
  memset(m_methods, 0, sizeof(m_methods));
  m_methods[nc::Window::Escape]	= &ControlPanel::exit;
  m_methods[nc::Window::Resize]	= &ControlPanel::resize;
  m_methods[nc::Window::Right]	= &ControlPanel::incrementIndex;
  m_methods[nc::Window::Left]	= &ControlPanel::decrementIndex;
  m_methods[nc::Window::Del]	= &ControlPanel::deleteCharFromPrompt;
  m_methods[nc::Window::Enter]	= &ControlPanel::confirmCommand;

  this->resize();
}

ControlPanel::~ControlPanel()
{
}


ControlPanel::EventMethod
ControlPanel::getHandler(nc::Window::Event event) const
{
  EventMethod	method;

  method = NULL;
  if (event < MAX_EVENT_CODE)
    method = m_methods[event];

  return (method);
}


void
ControlPanel::exit()
{
  m_loop = false;
}

void
ControlPanel::resize()
{
  int	width, height;

  this->getWidthAndHeight(width, height);
  m_logs.resize(width - width / 4, height - 3);
  m_logs.displace(width / 4, 0);
  m_prompt.resize(width, 3);
  m_prompt.displace(0, height - 3);
}

void
ControlPanel::incrementIndex()
{
  m_prompt.incrementIndex();
}

void
ControlPanel::decrementIndex()
{
  m_prompt.decrementIndex();
}

void
ControlPanel::deleteCharFromPrompt()
{
  m_prompt.deleteChar();
}

void
ControlPanel::confirmCommand()
{
  const char*	input;

  input = m_prompt.getInput();
  if (input[0] != '\0')
    this->executeCommand(input);
  m_prompt.clear();
}


void
ControlPanel::manageDisplay() const
{
  m_logs.draw();
  m_prompt.draw();
}

bool
ControlPanel::manageData()
{
  bool	mustDraw;

  m_clock.update();
  m_remainingTime -= m_clock.getElapsedTime();
  mustDraw = (m_remainingTime <= 0);
  if (mustDraw)
    m_remainingTime += 1000000 / CONSOLE_FRAMERATE;

  m_logs.update();
  m_prompt.update();

  return (mustDraw);
}

void
ControlPanel::catchInput()
{
  nc::Window::Event	event;
  EventMethod	        method;

  event = this->getEvent();
  method = this->getHandler(event);
  if (method != NULL)
    (this->*method)();
  else if (IS_PRINTABLE(event))
    m_prompt.addChar(event);
}

void
ControlPanel::manageEvents()
{
  struct timeval	timeout;
  fd_set		fds;

  timeout.tv_sec = 0;
  timeout.tv_usec = m_remainingTime;

  FD_ZERO(&fds);
  FD_SET(STDIN_FILENO, &fds);
  select(1, &fds, NULL, NULL, &timeout);

  if (FD_ISSET(STDIN_FILENO, &fds))
    this->catchInput();
}


void
ControlPanel::run()
{
  m_loop = true;

  this->clear();
  this->display();

  do
    {
      if (this->manageData())
	this->manageDisplay();
      this->manageEvents();
    }
  while (m_loop);
}
