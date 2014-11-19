//
// LogManager.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Mon Oct 20 08:48:33 2014 
// Last Update Tue Nov 18 11:59:35 2014 
//

#include "debug/LogManager.hh"
#include "debug/StandartLog.hh"
#include "exceptions/SyscallException.hh"

#include <cstring>

LogManager::LogManager(const char* file) :
  m_buffer(NULL),
  m_consoleMode(false)
{
  m_stream = fopen(file, "w");
  if (m_stream == NULL)
    throw SyscallException("Cannot create log file");

  this->initStandartLogs();
  this->initTabs();
}

LogManager::~LogManager()
{
  if (m_buffer != NULL)
    delete (m_buffer);
  this->deleteLogs();

  if (fclose(m_stream) != 0)
    throw SyscallException("Cannot close log file");
}


void
LogManager::initStandartLogs()
{
  debug = new StandartLog(stdout, DEBUG_COLOR, DEBUG_BOLD, false);
  input = new StandartLog(stdout, INPUT_COLOR, INPUT_BOLD, true);
  output = new StandartLog(stdout, OUTPUT_COLOR, OUTPUT_BOLD, true);
  graphicInput = new StandartLog(stdout, GRAPHIC_INPUT_COLOR, GRAPHIC_INPUT_BOLD, true);
  graphicOutput = new StandartLog(stdout, GRAPHIC_OUTPUT_COLOR, GRAPHIC_OUTPUT_BOLD, false);
  iaInput = new StandartLog(stdout, IA_INPUT_COLOR, IA_INPUT_BOLD, true);
  iaOutput = new StandartLog(stdout, IA_OUTPUT_COLOR, IA_OUTPUT_BOLD, true);
  intern = new StandartLog(stdout, INTERN_COLOR, INTERN_BOLD, false);
  events = new StandartLog(stdout, THREADING_COLOR, THREADING_BOLD, true);
  connection = new StandartLog(stdout, CONNECTION_COLOR, CONNECTION_BOLD, true);
  error = new StandartLog(stderr, ERROR_COLOR, ERROR_BOLD, true);
}

void
LogManager::initConsoleLogs()
{
  debug = new ConsoleLog(DEBUG_COLOR, DEBUG_BOLD, false);
  input = new ConsoleLog(INPUT_COLOR, INPUT_BOLD, true);
  output = new ConsoleLog(OUTPUT_COLOR, OUTPUT_BOLD, true);
  graphicInput = new ConsoleLog(GRAPHIC_INPUT_COLOR, GRAPHIC_INPUT_BOLD, true);
  graphicOutput = new ConsoleLog(GRAPHIC_OUTPUT_COLOR, GRAPHIC_OUTPUT_BOLD, false);
  iaInput = new ConsoleLog(IA_INPUT_COLOR, IA_INPUT_BOLD, true);
  iaOutput = new ConsoleLog(IA_OUTPUT_COLOR, IA_OUTPUT_BOLD, true);
  intern = new ConsoleLog(INTERN_COLOR, INTERN_BOLD, false);
  events = new ConsoleLog(THREADING_COLOR, THREADING_BOLD, true);
  connection = new ConsoleLog(CONNECTION_COLOR, CONNECTION_BOLD, true);
  error = new ConsoleLog(ERROR_COLOR, ERROR_BOLD, true);
}

void
LogManager::initTabs()
{
  m_names[ 0] = "debug";		m_logs[ 0] = &debug;
  m_names[ 1] = "input";		m_logs[ 1] = &input;
  m_names[ 2] = "output";		m_logs[ 2] = &output;
  m_names[ 3] = "graphicInput";		m_logs[ 3] = &graphicInput;
  m_names[ 4] = "graphicOutput";	m_logs[ 4] = &graphicOutput;
  m_names[ 5] = "iaInput";		m_logs[ 5] = &iaInput;
  m_names[ 6] = "iaOutput";		m_logs[ 6] = &iaOutput;
  m_names[ 7] = "intern";		m_logs[ 7] = &intern;
  m_names[ 8] = "events";		m_logs[ 8] = &events;
  m_names[ 9] = "connection";		m_logs[ 9] = &connection;
  m_names[10] = "error";		m_logs[10] = &error;
}


void
LogManager::deleteLogs()
{
  delete (debug);
  delete (input);
  delete (output);
  delete (graphicInput);
  delete (graphicOutput);
  delete (iaInput);
  delete (iaOutput);
  delete (intern);
  delete (events);
  delete (connection);
  delete (error);
}


void
LogManager::setConsoleMode()
{
  m_consoleMode = true;
  this->deleteLogs();
  this->initConsoleLogs();
  m_buffer = new ConsoleBuffer;
}


Log*
LogManager::getLogFromName(const char* name)
{
  Log*		log;
  unsigned int	index;

  log = NULL;
  for (index = 0; log == NULL && index < LOGS_NUMBER; ++index)
    if (!strcmp(m_names[index], name))
      log = *m_logs[index];

  return (log);
}
