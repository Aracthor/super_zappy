//
// Client.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Mon Oct 13 17:07:49 2014 
// Last Update Sat Nov  8 17:50:22 2014 
//

#ifndef CLIENT_HH_
# define CLIENT_HH_

# include "containers/Buffer.hh"
# include "data/Team.hh"
# include "map/Hoopla.hh"
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
  void		printInput(const char* packet, int id) const;
  void		printOutput(const char* packet, int id) const;

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

public:
  Client&	operator<<(const char* data);
  Client&	operator<<(char* data);
  Client&	operator<<(char data);
  Client&	operator<<(bool data);
  void		operator<<(const Player& player);
  void		operator<<(const Team& team);

  // For numbers and enums
  template <typename T>
  Client&	operator<<(T data);
};

# include "Client.hpp"

#endif // !CLIENT_HH_
