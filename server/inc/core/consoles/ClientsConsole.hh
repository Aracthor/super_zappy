//
// ClientsConsole.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Wed Nov 19 09:19:03 2014 
// Last Update Wed Nov 19 09:57:14 2014 
//

#ifndef CLIENTS_CONSOLE_HH_
# define CLIENTS_CONSOLE_HH_

# include "DataConsole.hh"
# include "network/Client.hh"

class			ClientsConsole : public DataConsole<Client>
{
private:
  struct		ClientType
  {
    const char*		name;
    nc::Color		color;
  };

private:
  ClientType		m_unknow;
  ClientType		m_graphic;
  ClientType		m_team;

public:
  ClientsConsole();
  ~ClientsConsole();

private:
  void	drawClient(const Client& client, const ClientType& type) const;

protected:
  void	drawElemData(const Client& client) const;

public:
  void	drawData() const;
};

#endif // !CLIENTS_CONSOLE_HH_
