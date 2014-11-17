//
// Console.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Nov 16 17:20:59 2014 
// Last Update Sun Nov 16 17:35:26 2014 
//

#include "core/consoles/Console.hh"

Console::Console(const std::string& name) :
  nc::Window(name),
  m_borderColor(COLOR_BLACK, COLOR_WHITE)
{
}

Console::~Console()
{
}


void
Console::draw() const
{
  this->clear();
  {
    this->setColor(m_borderColor);
    {
      this->drawBorder();
    }
    this->unsetColor(m_borderColor);
    this->drawData();
  }
  this->display();
}
