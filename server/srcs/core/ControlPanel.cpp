//
// ControlPanel.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Nov 16 16:43:06 2014 
// Last Update Thu Nov 20 13:37:24 2014 
//

#include "core/ControlPanel.hh"
#include "core/consoles/ClientsConsole.hh"
#include "core/consoles/LogsConsole.hh"
#include "core/consoles/PlayersConsole.hh"

#include <cstring>

ControlPanel::ControlPanel() :
  m_logThread(this),
  m_remainingTime(0),
  m_dataIndex(0)
{
  memset(m_methods, 0, sizeof(m_methods));
  m_methods[nc::Window::Escape]	= &ControlPanel::exit;
  m_methods[nc::Window::Resize]	= &ControlPanel::resize;
  m_methods[nc::Window::Right]	= &ControlPanel::incrementIndex;
  m_methods[nc::Window::Left]	= &ControlPanel::decrementIndex;
  m_methods[nc::Window::CRight]	= &ControlPanel::incrementConsoleIndex;
  m_methods[nc::Window::CLeft]	= &ControlPanel::decrementConsoleIndex;
  m_methods[nc::Window::Del]	= &ControlPanel::deleteCharFromPrompt;
  m_methods[nc::Window::Enter]	= &ControlPanel::confirmCommand;

  m_dataConsoles[0] = new ClientsConsole;
  m_dataConsoles[1] = new PlayersConsole;
  m_dataConsoles[2] = new LogsConsole;

  this->resize();
}

ControlPanel::~ControlPanel()
{
  unsigned int	i;

  for (i = 0; i < DATA_CONSOLES_NUMBER; ++i)
    delete (m_dataConsoles[i]);
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
ControlPanel::doToDataConsoles(DataConsoleMethod method) const
{
  unsigned int	i;

  for (i = 0; i < DATA_CONSOLES_NUMBER; ++i)
    (this->*method)(m_dataConsoles[i]);
}

void
ControlPanel::resizeDataConsole(Console* dataConsole) const
{
  int	width, height;

  this->getWidthAndHeight(width, height);
  dataConsole->resize(width / 4, height - 3);
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

  m_mutex.lock();
  {
    this->getWidthAndHeight(width, height);
    if (width > MIN_CONSOLE_WIDTH && height > MIN_CONSOLE_HEIGHT)
      {
	this->doToDataConsoles(&ControlPanel::resizeDataConsole);
	m_logs.resize(width - width / 4, height - 3);
	m_logs.displace(width / 4, 0);
	m_prompt.resize(width, 3);
	m_prompt.displace(0, height - 3);
      }
  }
  m_mutex.unlock();
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
ControlPanel::incrementConsoleIndex()
{
  ++m_dataIndex;
  if (m_dataIndex == DATA_CONSOLES_NUMBER)
    m_dataIndex = 0;
}

void
ControlPanel::decrementConsoleIndex()
{
  if (m_dataIndex == 0)
    m_dataIndex = DATA_CONSOLES_NUMBER;
  --m_dataIndex;
}

void
ControlPanel::deleteCharFromPrompt()
{
  m_mutex.lock();
  m_prompt.deleteChar();
  m_mutex.unlock();
}

void
ControlPanel::confirmCommand()
{
  const char*	input;

  input = m_prompt.getInput();
  if (input[0] != '\0')
    this->executeCommand(input);

  m_mutex.lock();
  m_prompt.clear();
  m_mutex.unlock();
}


void
ControlPanel::manageDisplay() const
{
  m_dataConsoles[m_dataIndex]->draw();
  m_logs.draw();
  m_prompt.draw();
}

void
ControlPanel::manageData()
{
  m_dataConsoles[m_dataIndex]->update();
  m_logs.update();
  m_prompt.update();
}

void
ControlPanel::manageEvents()
{
  nc::Window::Event	event;
  EventMethod		method;

  event = this->getEvent();
  method = this->getHandler(event);

  if (method != NULL)
    (this->*method)();
  else if (IS_PRINTABLE(event))
    {
      m_mutex.lock();
      m_prompt.addChar(event);
      m_mutex.unlock();
    }
}


void
ControlPanel::update()
{
  int	width, height;

  m_mutex.lock();
  {
    this->getWidthAndHeight(width, height);
    if (width > MIN_CONSOLE_WIDTH && height > MIN_CONSOLE_HEIGHT)
      {
	this->manageData();
	this->manageDisplay();
      }
    else if (width > 1 && height > 1)
      {
	this->clear();
	this->move(0, 0);
	this->print("Fuck you");
	this->display();
      }
  }
  m_mutex.unlock();
}

void
ControlPanel::run()
{
  m_loop = true;

  this->clear();
  this->display();

  m_logThread.start();

  do
    {
      this->manageEvents();
    }
  while (m_loop);

  m_logThread.interrupt();
  m_logThread.join();
}
