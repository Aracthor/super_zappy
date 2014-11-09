//
// Client.hpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Tue Oct 14 13:02:33 2014 
// Last Update Sat Nov  8 18:48:43 2014 
//

#include "debug/LogManager.hh"
#include "network/Protocol.hh"

#include <cstring>

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

const Team*
Client::getTeam() const
{
  return (m_team);
}

Team*
Client::getTeam()
{
  return (m_team);
}


void
Client::giveTeam(Team* team)
{
  m_team = team;
}

void
Client::setTeam()
{
  m_isPlayer = true;
}

void
Client::setGraphic()
{
  m_isGraphic = true;
}


template <typename T>
Client&
Client::operator<<(T number)
{
  if (number < 0)
    {
      *this << '-';
      number = static_cast<T>(-static_cast<int>(number));
    }

  if (number > 9)
    *this << static_cast<T>(number / 10);
  *this << static_cast<char>(number % static_cast<T>(10) + '0');

  return *this;
}
