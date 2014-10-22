//
// Server.hpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Tue Oct 21 10:11:17 2014 
// Last Update Wed Oct 22 12:27:03 2014 
//

Server*
Server::accessServer()
{
  return (s_server);
}


unsigned int
Server::getSpeed() const
{
  return (m_speed);
}
