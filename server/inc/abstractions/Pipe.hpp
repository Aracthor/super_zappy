//
// Pipe.hpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Tue Nov 18 08:13:32 2014 
// Last Update Tue Nov 18 08:23:24 2014 
//

#include "exceptions/SyscallException.hh"

#include <unistd.h>

void
Pipe::closeInput()
{
  this->closeFd(0);
}

void
Pipe::closeOutput()
{
  this->closeFd(1);
}

Pipe::fd
Pipe::getInput() const
{
  return (m_fd[0]);
}

Pipe::fd
Pipe::getOutput() const
{
  return (m_fd[0]);
}


template <typename T>
void
Pipe::operator<<(const T& elem) const
{
  if (write(m_fd[1], &elem, sizeof(elem)) == -1)
    throw SyscallException("Error writing in pipe : ");
}

template <typename T>
void
Pipe::operator>>(T& elem) const
{
  if (read(m_fd[0], &elem, sizeof(elem)) == -1)
    throw SyscallException("Error reading from pipe : ");
}
