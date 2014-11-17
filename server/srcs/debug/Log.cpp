//
// Log.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Mon Oct 20 10:15:01 2014 
// Last Update Mon Nov 17 13:45:41 2014 
//

#include "debug/Log.hh"

Log::Log(EColor color, bool bold, bool active) :
  m_color(color),
  m_bold(bold),
  m_active(active)
{
}

Log::~Log()
{
}


void
Log::print(const char* message, ...)
{
  if (m_active)
    {
      va_list	list;

      va_start(list, message);
      {
	this->print(message, list);
      }
      va_end(list);
    }
}
