//
// ClientsConsole.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Wed Nov 19 09:23:22 2014 
// Last Update Wed Nov 19 09:57:54 2014 
//

#include "core/Server.hh"
#include "core/consoles/ClientsConsole.hh"

ClientsConsole::ClientsConsole() :
  DataConsole<Client>("Clients")
{
  m_unknow.name = "Unknow";	m_unknow.color = nc::Color(COLOR_BLUE, COLOR_BLACK);
  m_graphic.name = "Graphic";	m_graphic.color = nc::Color(COLOR_CYAN, COLOR_BLACK);
  m_team.name = "Team";		m_team.color = nc::Color(COLOR_MAGENTA, COLOR_BLACK);
}

ClientsConsole::~ClientsConsole()
{
}


void
ClientsConsole::drawClient(const Client& client, const ClientsConsole::ClientType& type) const
{
  this->setColor(type.color);
  {
    this->print("Client %d : %s", client.getFd(), type.name);
  }
  this->unsetColor(type.color);
}


void
ClientsConsole::drawElemData(const Client& client) const
{
  if (client.isGraphic())
    this->drawClient(client, m_graphic);
  else if (client.isPlayer())
    this->drawClient(client, m_team);
  else
    this->drawClient(client, m_unknow);
}


void
ClientsConsole::drawData() const
{
  unsigned int	i;

  this->activeAttr(A_BOLD);
  {
    for (i = 0; i < this->getServerData()->getClients().getSize(); ++i)
      this->drawElem(this->getServerData()->getClients()[i], i);
  }
  this->disactiveAttr(A_BOLD);
}
