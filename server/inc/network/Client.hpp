//
// Client.hpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Tue Oct 14 13:02:33 2014 
// Last Update Tue Oct 21 11:09:41 2014 
//

Client::ClientBuffer&
Client::getInput()
{
  return (m_input);
}

Client::ClientBuffer&
Client::getOutput()
{
  return (m_output);
}

bool
Client::isPlayer() const
{
  return (m_isPlayer);
}

bool
Client::isGraphic() const
{
  return (m_isGraphic);
}

int
Client::getFd() const
{
  return (m_socket.getFd());
}

bool
Client::wantToSpeak() const
{
  return (!m_output.isEmpty());
}


void
Client::setPlayer()
{
  m_isPlayer = true;
}

void
Client::setGraphic()
{
  m_isGraphic = true;
}
