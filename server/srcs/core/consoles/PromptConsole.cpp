//
// PromptConsole.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Mon Nov 17 17:04:05 2014 
// Last Update Tue Nov 18 08:33:59 2014 
//

#include "core/consoles/PromptConsole.hh"

PromptConsole::PromptConsole() :
  Console("Prompt"),
  m_index(0)
{
}

PromptConsole::~PromptConsole()
{
}


void
PromptConsole::incrementIndex()
{
  if (m_index < m_buffer.getSize())
    ++m_index;
}

void
PromptConsole::decrementIndex()
{
  if (m_index > 0)
    --m_index;
}

void
PromptConsole::addChar(char c)
{
  if (static_cast<int>(m_buffer.getSize()) < this->getWidth() - 2)
    {
      m_buffer.insertAt(c, m_index);
      ++m_index;
    }
}

void
PromptConsole::deleteChar()
{
  if (m_index > 0)
    {
      m_buffer.popAt(m_index - 1);
      --m_index;
    }
}

void
PromptConsole::clear()
{
  m_buffer.reset();
  m_index = 0;
}


void
PromptConsole::update()
{
}

void
PromptConsole::drawData() const
{
  this->move(1, 1);
  this->print("%s", m_buffer.getData());
  this->move(m_index + 1, 1);
}
