//
// Socket.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Oct 12 06:26:47 2014 
// Last Update Sun Nov 16 16:09:09 2014 
//

#include "debug/LogManager.hh"
#include "exceptions/NetworkException.hh"
#include "network/Socket.hh"

#include <cstring>
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

Socket::Socket() :
  m_isCopy(false)
{
}

Socket::Socket(const Socket& socket) :
  m_fd(socket.m_fd),
  m_isCopy(false)
{
  socket.m_isCopy = true;
}

Socket::~Socket()
{
  if (m_isCopy == false)
    {
      if (close(m_fd) == -1)
	throw NetworkException("Cannot close socket : ");
    }
}


void
Socket::createSocket()
{
  struct protoent*	pe;
  int			useless_int;

  pe = getprotobyname("TCP");
  useless_int = 1;

  m_fd = socket(AF_INET, SOCK_STREAM, pe->p_proto);
  if (m_fd == -1 ||
      setsockopt(m_fd, SOL_SOCKET, SO_REUSEADDR, &useless_int, sizeof(int)) == -1)
    throw NetworkException("Cannot create socket : ");
}

void
Socket::bind(unsigned int port)
{
  struct sockaddr_in	s_in;

  s_in.sin_family = AF_INET;
  s_in.sin_port = htons(port);
  s_in.sin_addr.s_addr = INADDR_ANY;

  if (::bind(m_fd, (const struct sockaddr *)&s_in, sizeof(s_in)) == -1)
    throw NetworkException("Cannot bind socket : ");
}

void
Socket::listen(unsigned int clients)
{
  if (::listen(m_fd, clients) == -1)
    throw NetworkException("Cannot listen on socket : ");
}

void
Socket::accept(const Socket& serverSocket)
{
  struct sockaddr_in    infos;
  socklen_t             size;

  memset(&infos, 0, sizeof(infos));

  size = sizeof(infos);
  m_fd = ::accept(serverSocket.getFd(), (struct sockaddr*)&infos, &size);
  if (m_fd == -1)
    throw NetworkException("Cannot accept on socket : ");

  LogManagerSingleton::access()->connection->print("Client connected with domain %s, "
						   "id attribued : %d.",
						   inet_ntoa(infos.sin_addr), m_fd);
}


Socket&
Socket::operator=(const Socket& copy)
{
  m_fd = copy.m_fd;
  m_isCopy = false;
  copy.m_isCopy = true;

  return (*this);
}
