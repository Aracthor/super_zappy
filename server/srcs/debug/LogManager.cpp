//
// LogManager.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Mon Oct 20 08:48:33 2014 
// Last Update Sun Nov  9 03:35:28 2014 
//

#include "debug/LogManager.hh"

LogManager::LogManager() :
  debug(stdout, DEBUG_COLOR, DEBUG_BOLD, true),
  input(stdout, INPUT_COLOR, INPUT_BOLD, true),
  output(stdout, OUTPUT_COLOR, OUTPUT_BOLD, true),
  graphicInput(stdout, GRAPHIC_INPUT_COLOR, GRAPHIC_INPUT_BOLD, true),
  graphicOutput(stdout, GRAPHIC_OUTPUT_COLOR, GRAPHIC_OUTPUT_BOLD, false),
  iaInput(stdout, IA_INPUT_COLOR, IA_INPUT_BOLD, true),
  iaOutput(stdout, IA_OUTPUT_COLOR, IA_OUTPUT_BOLD, true),
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
