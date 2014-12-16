//
// TeamsConsole.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Thu Dec 11 09:22:42 2014 
// Last Update Thu Dec 11 09:23:47 2014 
//

#include "core/Server.hh"
#include "core/consoles/TeamsConsole.hh"

TeamsConsole::TeamsConsole() :
  DataConsole<Team>("Teams"),
  m_colors(this->getServerData()->getTeamsNumber())
{
}

TeamsConsole::~TeamsConsole()
{
}


void
TeamsConsole::drawElemData(const Team& team) const
{
  unsigned int	colorIndex;

  colorIndex = this->getServerData()->getTeamId(team);
  this->move(1, m_index + 1);
  this->setColor(m_colors.getColor(colorIndex));
  {
    this->print("Team %s", team.getName());
  }
  this->unsetColor(m_colors.getColor(colorIndex));
  ++m_index;
}


static void
drawTeam(const Team& team, const TeamsConsole& console)
{
  console.drawElemData(team);
}

void
TeamsConsole::drawData() const
{
  m_index = 0;
  this->activeAttr(A_BOLD);
  {
    this->getServerData()->doToTeams(&drawTeam, *this);
  }
  this->disactiveAttr(A_BOLD);
}
