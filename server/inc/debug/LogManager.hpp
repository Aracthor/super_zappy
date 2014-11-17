//
// LogManager.hpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Nov 16 17:59:48 2014 
// Last Update Mon Nov 17 13:59:52 2014 
//

void
LogManager::lock()
{
  m_lock.lock();
}

void
LogManager::unlock()
{
  m_lock.unlock();
}

LogManager::ConsoleBuffer*
LogManager::getBuffer()
{
  return (m_buffer);
}


void
LogManager::addToFile(const char* message)
{
  fprintf(m_stream, "%s\n", message);
}
