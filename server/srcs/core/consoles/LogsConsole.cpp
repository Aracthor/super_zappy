//
// LogsConsole.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Thu Nov 20 11:00:42 2014 
// Last Update Thu Nov 20 11:22:38 2014 
//

#include "core/consoles/LogsConsole.hh"
#include "debug/LogManager.hh"

LogsConsole::LogsConsole() :
  DataConsole<Log>("Logs"),
  m_colorFactory(LOGS_COLORS_NUMBER)
{
}

LogsConsole::~LogsConsole()
{
}


void
LogsConsole::drawElemData(const Log& log) const
{
  this->setColor(m_colorFactory.getColor(log.getColor() - 1));
  if (log.isBold())
    this->activeAttr(A_BOLD);
  {
    this->print("%s: %s", log.getName(), log.isActive() ? "on" : "off");
  }
  if (log.isBold())
    this->disactiveAttr(A_BOLD);
  this->unsetColor(m_colorFactory.getColor(log.getColor() - 1));
}


void
LogsConsole::drawData() const
{
  const Log* const*	logs;
  unsigned int		i;

  logs = LogManagerSingleton::access()->getLogList();

  for (i = 0; i < LOGS_NUMBER; ++i)
    this->drawElem(*logs[i], i);
}
