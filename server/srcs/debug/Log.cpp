//
// Log.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Mon Oct 20 10:15:01 2014 
// Last Update Fri Oct 24 17:05:45 2014 
//

#include <stdarg.h>

#include "debug/Log.hh"

Log::Log(FILE* stream, Log::EColor color, bool bold, bool active) :
  m_stream(stream),
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
	fprintf(m_stream, "\033[0%d;3%dm", m_bold, m_color);
	vfprintf(m_stream, message, list);
	fprintf(m_stream, "\033[0m\n");
      }
      va_end(list);
    }
}
