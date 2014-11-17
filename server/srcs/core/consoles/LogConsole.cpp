//
// LogConsole.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Nov 16 17:14:40 2014 
// Last Update Mon Nov 17 16:39:58 2014 
//

#include "core/consoles/LogConsole.hh"
#include "debug/LogManager.hh"

#include <cstdio>
#include <cstring>
#include <ncursesw/curses.h>

LogConsole::LogConsole() :
  Console("Logs")
{
  m_colors[0] = nc::Color(COLOR_BLACK, COLOR_BLACK);
  m_colors[1] = nc::Color(COLOR_RED, COLOR_BLACK);
  m_colors[2] = nc::Color(COLOR_GREEN, COLOR_BLACK);
  m_colors[3] = nc::Color(COLOR_YELLOW, COLOR_BLACK);
  m_colors[4] = nc::Color(COLOR_BLUE, COLOR_BLACK);
  m_colors[5] = nc::Color(COLOR_MAGENTA, COLOR_BLACK);
  m_colors[6] = nc::Color(COLOR_CYAN, COLOR_BLACK);
  m_colors[7] = nc::Color(COLOR_WHITE, COLOR_BLACK);
}

LogConsole::~LogConsole()
{
}


void
LogConsole::update()
{
  LogManager::ConsoleBuffer*	buffer;

  LogManagerSingleton::access()->lock();
  {
    buffer = LogManagerSingleton::access()->getBuffer();
    m_buffer.copyFrom(*buffer);
    buffer->clear();
  }
  LogManagerSingleton::access()->unlock();
}


void
LogConsole::printLine(const char* buffer, const char* line) const
{
  if (line[0] != '0' && line[0] != '1')
    this->print(buffer, line);

  else
    {
      if (line[1] > '0')
	this->setColor(m_colors[line[1] - '0']);
      if (line[0] == '1')
	this->activeAttr(A_BOLD);

      this->print(buffer, &line[2]);
    }
}

const char*
LogConsole::drawLine(const char* data, const char* line) const
{
  const char*	ptr;
  const char*	printable;
  unsigned int	size;
  char		buffer[0x100];

  ptr = line - 1;
  while (*ptr != '\n' && ptr > data)
    --ptr;

  printable = ptr;
  if (*ptr == '\n')
    ++printable;

  size = MIN(line - printable, this->getWidth() - 2);
  if (size > 2 && (printable[0] == '0' || printable[0] == '1'))
    size -= 2;
  sprintf(buffer, "%%.%ds", size);
  this->printLine(buffer, printable);

  return (ptr);
}

void
LogConsole::drawData() const
{
  const char*	ptr;
  int		y;

  ptr = m_buffer.getEnd() - 1;

  for (y = this->getHeight() - 2; ptr != m_buffer.getData() && y > 0; --y)
    {
      this->move(1, y);
      ptr = this->drawLine(m_buffer.getData(), ptr);
    }

  if (y == 0)
    m_buffer.popFront(ptr - m_buffer.getData());
}
