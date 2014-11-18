//
// AExecuter.hpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Tue Nov 18 10:26:24 2014 
// Last Update Tue Nov 18 10:55:17 2014 
//

#include "exceptions/StartException.hh"

template <class T>
void
AExecuter::addCommand(const char* name, void (T::*method)(const char* param))
{
  if (m_index == MAX_EXECUTIONS_NUMBER)
    throw StartException("You need to increment maccro MAX_EXECUTIONS_NUMBER.");

  m_commands[m_index] = name;
  m_executions[m_index] = reinterpret_cast<Execution>(method);
  ++m_index;
}
