//
// PlayersConsole.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Wed Nov 19 10:20:07 2014 
// Last Update Wed Nov 19 10:48:33 2014 
//

#include "core/Server.hh"
#include "core/consoles/PlayersConsole.hh"

PlayersConsole::PlayersConsole() :
  DataConsole<Player>("Players"),
  m_colors(this->getServerData()->getTeamsNumber())
{
}

PlayersConsole::~PlayersConsole()
{
}


void
PlayersConsole::drawElemData(const Player& player) const
{
  unsigned int	colorIndex;

  colorIndex = this->getServerData()->getTeamId(*player.getTeam());
  this->move(1, m_index + 1);
  this->setColor(m_colors.getColor(colorIndex));
  {
    this->print("%s : %s of team %s",
		player.getName(), player.getClass()->getName(), player.getTeam()->getName());
  }
  this->unsetColor(m_colors.getColor(colorIndex));
  ++m_index;
}


static void
drawPlayer(const Player& player, const PlayersConsole& console)
{
  console.drawElemData(player);
}

void
PlayersConsole::drawData() const
{
  m_index = 0;
  this->activeAttr(A_BOLD);
  {
    this->getServerData()->doToPlayers(&drawPlayer, *this);
  }
  this->disactiveAttr(A_BOLD);
}
