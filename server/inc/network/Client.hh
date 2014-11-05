//
// Client.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Mon Oct 13 17:07:49 2014 
// Last Update Tue Nov  4 09:43:43 2014 
//

#ifndef CLIENT_HH_
# define CLIENT_HH_

# include "containers/Buffer.hh"
# include "data/Team.hh"
# include "Socket.hh"

# define CLIENT_BUFFER_SIZE	(0x4000)

class		Client
{
private:
  typedef Buffer<CLIENT_BUFFER_SIZE>	ClientBuffer;

private:
  Socket	m_socket;
  ClientBuffer	m_input;
  ClientBuffer	m_output;
  bool		m_isPlayer;
  bool		m_isGraphic;
  bool		m_endIminent;
  Team*		m_team;

public:
  Client(const Socket& serverSocket);
  Client(const Client& copy);
  ~Client();

private:
  bool		checkError(int size, const char* word);
  bool		checkEnd(int size);
  void		addRecvToInput(int size);
  void		subSentFromOutput(int size);

public:
  bool		recv();
  bool		send();
  void		send(const char* data);

public:
  inline ClientBuffer&	getInput();
  inline ClientBuffer&	getOutput();
  inline bool		isPlayer() const;
  inline bool		isGraphic() const;
  inline int		getFd() const;
  inline bool		wantToSpeak() const;
  inline const Team*    getTeam() const;
  inline Team*		getTeam();

public:
  inline void		giveTeam(Team* team);
  inline void		setTeam();
  inline void		setGraphic();

public:
  Client&	operator=(const Client& copy);
  void		operator<<(const char* data);
};

#include "Client.hpp"

#endif // !CLIENT_HH_
