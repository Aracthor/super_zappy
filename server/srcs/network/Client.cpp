//
// Client.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Tue Oct 14 13:07:56 2014 
// Last Update Thu Dec 11 09:18:24 2014 
//

#include "debug/LogManager.hh"
#include "network/Client.hh"
#include "network/Protocol.hh"

#include <cerrno>
#include <cstring>
#include <sys/socket.h>
#include <sys/types.h>

Client::Client(const Socket& serverSocket) :
  m_socket(),
  m_input(),
  m_output(WELCOME_MESSAGE),
  m_isPlayer(false),
  m_isGraphic(false),
  m_endIminent(false),
  m_team(NULL)
{
  m_socket.accept(serverSocket);
}

Client::Client(const Client& copy) :
  m_socket(copy.m_socket),
  m_input(copy.m_input),
  m_output(copy.m_output),
  m_isPlayer(copy.m_isPlayer),
  m_isGraphic(copy.m_isGraphic),
  m_endIminent(false),
  m_team(NULL)
{
}

Client::~Client()
{
  if (m_socket.isCopy() == false)
    LogManagerSingleton::access()->connection->print("Client %d disconnected.",
						     m_socket.getFd());
}


void
Client::printInput(const char* packet, int id) const
{
  if (m_isGraphic)
    LogManagerSingleton::access()->graphicInput->print("Data from client %d :\t'%s'",
						       id, packet);
  else if (m_isPlayer)
    LogManagerSingleton::access()->iaInput->print("Data from client %d :\t'%s'",
						  id, packet);
  else
    LogManagerSingleton::access()->input->print("Data from client %d :\t'%s'",
						id, packet);
}

void
Client::printOutput(const char* packet, int id) const
{
  if (m_isGraphic)
    LogManagerSingleton::access()->graphicOutput->print("Data to client %d :\t'%s'",
							id, packet);
  else if (m_isPlayer)
    LogManagerSingleton::access()->iaOutput->print("Data to client %d :\t'%s'",
						   id, packet);
  else
    LogManagerSingleton::access()->output->print("Data to client %d :\t'%s'",
						 id, packet);
}


bool
Client::checkError(int size, const char* word)
{
  bool	end;

  end = (size == -1 && (errno != EAGAIN && errno != EWOULDBLOCK));
  if (end)
    LogManagerSingleton::access()->error->print("Error %sing client %d : %s",
						word, m_socket.getFd(), strerror(errno));

  return (end);
}

bool
Client::checkEnd(int size)
{
  bool	end;

  end = (size == 0 && m_endIminent == true);
  m_endIminent = true;

  return (end);
}

void
Client::addRecvToInput(int size)
{
  if (size > 0)
    {
      m_input.getEnd()[size] = '\0';
      this->printInput(m_input.getEnd(), m_socket.getFd());
      m_input.addToSize(size);
      m_endIminent = false;
    }
}

void
Client::subSentFromOutput(int size)
{
  char	buffer[CLIENT_BUFFER_SIZE];

  if (size > 0)
    {
      strncpy(buffer, m_output.getData(), size);
      buffer[size] = '\0';
      this->printOutput(buffer, m_socket.getFd());
      m_output.popFront(size);
      m_endIminent = false;
    }
}


bool
Client::recv()
{
  bool	end;
  int	size;

  end = false;
  size = ::recv(m_socket.getFd(), m_input.getEnd(), CLIENT_BUFFER_SIZE - m_input.getSize(),
		MSG_DONTWAIT);

  end = this->checkError(size, "receiv");
  if (end == false)
    end = this->checkEnd(size);
  if (end == false)
    this->addRecvToInput(size);

  return (!end);
}

bool
Client::send()
{
  int	size;
  bool	end;

  size = ::send(m_socket.getFd(), m_output.getData(), m_output.getSize(), MSG_DONTWAIT);
  end = false;

  end = this->checkError(size, "send");
  if (end == false)
    end = this->checkEnd(size);
  if (end == false)
    this->subSentFromOutput(size);

  return (!end);
}

void
Client::send(const char* data)
{
  int	size;

  size = ::send(m_socket.getFd(), data, strlen(data), MSG_DONTWAIT);
  if (size == static_cast<int>(strlen(data)))
    LogManagerSingleton::access()->output->print("Data to client %d :\t'%s'",
						 m_socket.getFd(), data);
}


Client&
Client::operator=(const Client& copy)
{
  this->m_socket = copy.m_socket;
  this->m_isPlayer = copy.m_isPlayer;
  this->m_isGraphic = copy.m_isGraphic;
  this->m_input = copy.m_input;
  this->m_output = copy.m_output;

  return (*this);
}


Client&
Client::operator<<(const char* data)
{
  unsigned int	size;

  size = strlen(data);

  if (m_output.getSize() + size >= CLIENT_BUFFER_SIZE)
    LogManagerSingleton::access()->error->print("Client %d has a full output buffer !",
						m_socket.getFd());
  else
    m_output.pushBack(data, size);

  return *this;
}

Client&
Client::operator<<(char* data)
{
  *this << const_cast<const char*>(data);
  return *this;
}

Client&
Client::operator<<(char data)
{
  if (m_output.getSize() + 1 >= CLIENT_BUFFER_SIZE)
    LogManagerSingleton::access()->error->print("Client %d has a full output buffer !",
						m_socket.getFd());
  else
    m_output.pushBack(data);

  return *this;
}

Client&
Client::operator<<(bool data)
{
  *this << (data ? "true" : "false");

  return *this;
}

void
Client::operator<<(const Player& player)
{
  *this << "PDC "
	<< player.getName() << ' '
	<< player.getPosition().x << ' '
	<< player.getPosition().y << ' '
	<< player.getOrientation() << ' '
	<< player.getTeam()->getName() << ' '
	<< player.getClass()->getName() << ' '
	<< (player.getEquipement() ? player.getEquipement()->getItem() : 0)
	<< LINE_SEPARATOR;
}

void
Client::operator<<(const Team& team)
{
  unsigned int	i;

  *this << "TDC "
	<< team.getName() << ' '
	<< team.isDiscalified()
	<< LINE_SEPARATOR;

  if (team.isDiscalified()== false)
    for (i = 0; i < team.getPlayers().size(); ++i)
      *this << team.getPlayers()[i];
}

void
Client::operator<<(const Hoopla& hoopla)
{
  *this << "CAS "
	<< hoopla.x << ' '
	<< hoopla.y << ' '
	<< hoopla.ground << ' '
	<< static_cast<int>(hoopla.height) << ' '
	<< hoopla.item << ' '
	<< hoopla.itemNumber << ' '
	<< hoopla.object
	<< LINE_SEPARATOR;
}
