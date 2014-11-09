//
// Action.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sat Nov  8 20:07:52 2014 
// Last Update Sun Nov  9 06:19:04 2014 
//

#include "actions/Action.hh"

Action::Action()
{
}

Action::Action(Player* player, EAction action, int time, const UData& data) :
  m_player(player),
  m_action(action),
  m_data(data),
  m_timer(time)
{
}

Action::Action(Player* player, EAction action, int time, bool boolean) :
  m_player(player),
  m_action(action),
  m_data(boolean),
  m_timer(time)
{
}

Action::~Action()
{
}


Action&
Action::operator=(const Action& copy)
{
  m_player = copy.m_player;
  m_action = copy.m_action;
  m_data = copy.m_data;
  m_timer = copy.m_timer;

  return *this;
}
