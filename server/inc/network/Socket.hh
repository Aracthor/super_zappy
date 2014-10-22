//
// Socket.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Oct 12 05:40:41 2014 
// Last Update Tue Oct 21 08:56:29 2014 
//

#ifndef SOCKET_HH_
# define SOCKET_HH_

# define MAX_LISTEN_CLIENTS	(42)

class	Socket
{
private:
  int		m_fd;
  mutable bool	m_isCopy;

public:
  Socket();
  Socket(const Socket& copy);
  ~Socket();

public:
  void	createSocket();
  void	bind(unsigned int port);
  void	listen(unsigned int clients);
  void	accept(const Socket& serverSocket);

public:
  inline int	getFd() const;
  inline bool	isCopy() const;

public:
  Socket&	operator=(const Socket& copy);
};

#include "Socket.hpp"

#endif // !SOCKET_HH_
