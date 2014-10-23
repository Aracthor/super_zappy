//
// GameData.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Wed Oct 22 13:29:09 2014 
// Last Update Wed Oct 22 13:46:18 2014 
//

#include "core/GameData.hh"

GameData::GameData(const Configs& configs) :
  m_teams(configs.getTeams()),
  m_speed(configs.getSpeed())
{
  
}

GameData::~GameData()
{
}
