//
// LogManager.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Mon Oct 20 08:48:33 2014 
// Last Update Mon Oct 20 13:53:18 2014 
//

#include "debug/LogManager.hh"

LogManager::LogManager() :
  input(stdout, INPUT_COLOR, INPUT_BOLD),
  output(stdout, OUTPUT_COLOR, OUTPUT_BOLD),
  intern(stdout, INTERN_COLOR, INTERN_BOLD),
  threading(stdout, THREADING_COLOR, THREADING_BOLD),
  connection(stdout, CONNECTION_COLOR, CONNECTION_BOLD),
  error(stderr, ERROR_COLOR, ERROR_BOLD)
{
  this->intern.print("Log manager created.");
}

LogManager::~LogManager()
{
}
