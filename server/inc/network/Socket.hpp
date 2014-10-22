//
// Socket.hpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Tue Oct 14 13:03:28 2014 
// Last Update Tue Oct 21 08:53:12 2014 
//

int
Socket::getFd() const
{
  return (m_fd);
}

bool
Socket::isCopy() const
{
  return (m_isCopy);
}
