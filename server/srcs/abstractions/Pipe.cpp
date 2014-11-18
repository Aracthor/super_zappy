//
// Pipe.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Tue Nov 18 08:08:23 2014 
// Last Update Tue Nov 18 08:13:38 2014 
//

#include "abstractions/Pipe.hh"
#include "exceptions/SyscallException.hh"

#include <unistd.h>

Pipe::Pipe()
{
  m_open[0] = true;
  m_open[1] = true;
  if (pipe(m_fd) == -1)
    throw SyscallException("Error creating pipe : ");
}

Pipe::~Pipe()
{
  this->closeInput();
  this->closeOutput();
}


void
Pipe::closeFd(int id)
{
  if (m_open[id] == true)
    {
      m_open[id] = false;
      if (close(m_fd[id]) == -1)
	throw SyscallException("Error closing pipe : ");
    }
}
