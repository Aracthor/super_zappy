//
// LogManager.hpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Nov 16 17:59:48 2014 
// Last Update Thu Nov 20 12:25:21 2014 
//

#include "exceptions/SyscallException.hh"

#include <unistd.h>

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

const Log* const*
LogManager::getLogList() const
{
  return (m_logs);
}


void
LogManager::addToFile(const char* message)
{
  if (write(m_fd, message, strlen(message)) == 1 || write(m_fd, "\n", 1) == -1)
    throw SyscallException("Cannot write in log file : ");
}
