//
// ControlPanel.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Nov 16 16:43:06 2014 
// Last Update Mon Nov 17 13:24:35 2014 
//

#include "core/ControlPanel.hh"

#include <cstring>
#include <sys/select.h>
#include <sys/time.h>
#include <unistd.h>

ControlPanel::ControlPanel()
{
  memset(m_methods, 0, sizeof(m_methods));
  m_methods[nc::Window::Escape]	= &ControlPanel::exit;
  m_methods[nc::Window::Resize]	= &ControlPanel::resize;

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
}


void
ControlPanel::manageDisplay() const
{
  m_logs.draw();
}

void
ControlPanel::manageData()
{
  m_logs.update();
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
}

void
ControlPanel::manageEvents()
{
  struct timeval	timeout;
  fd_set		fds;

  timeout.tv_sec = 0;
  timeout.tv_usec = 1000000 / CONSOLE_FRAMERATE;

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
  // m_logThread.start();

  do
    {
      this->clear();
      this->manageData();
      this->manageDisplay();
      this->manageEvents();
    }
  while (m_loop);

  // m_logThread.interrupt();
  // m_logThread.join();
}
