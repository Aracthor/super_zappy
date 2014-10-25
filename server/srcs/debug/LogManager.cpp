//
// LogManager.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Mon Oct 20 08:48:33 2014 
// Last Update Fri Oct 24 17:05:17 2014 
//

#include "debug/LogManager.hh"

LogManager::LogManager() :
  input(stdout, INPUT_COLOR, INPUT_BOLD, true),
  output(stdout, OUTPUT_COLOR, OUTPUT_BOLD, false),
  intern(stdout, INTERN_COLOR, INTERN_BOLD, true),
  threading(stdout, THREADING_COLOR, THREADING_BOLD, true),
  connection(stdout, CONNECTION_COLOR, CONNECTION_BOLD, true),
  error(stderr, ERROR_COLOR, ERROR_BOLD, true)
{
  this->intern.print("Log manager created.");
}

LogManager::~LogManager()
{
}
