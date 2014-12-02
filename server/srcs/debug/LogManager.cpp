//
// LogManager.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Mon Oct 20 08:48:33 2014 
// Last Update Sun Nov 23 10:33:46 2014 
//

#include "debug/LogManager.hh"
#include "debug/StandartLog.hh"
#include "exceptions/SyscallException.hh"

#include <cstring>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

LogManager::LogManager(const char* file) :
  m_buffer(NULL),
  m_consoleMode(false)
{
  m_fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
  if (m_fd == -1)
    throw SyscallException("Cannot open log file");

  this->initStandartLogs();
}

LogManager::~LogManager()
{
  if (m_buffer != NULL)
    delete (m_buffer);
  this->deleteLogs();

  if (close(m_fd) == -1)
    throw SyscallException("Cannot close log file");
}


void
LogManager::initStandartLogs()
{
  debug = new StandartLog("debug", stdout, DEBUG_COLOR, DEBUG_BOLD, false);
  input = new StandartLog("input", stdout, INPUT_COLOR, INPUT_BOLD, true);
  output = new StandartLog("output", stdout, OUTPUT_COLOR, OUTPUT_BOLD, true);
  graphicInput = new StandartLog("graphicInput", stdout, GRAPHIC_INPUT_COLOR, GRAPHIC_INPUT_BOLD, true);
  graphicOutput = new StandartLog("graphicOutput", stdout, GRAPHIC_OUTPUT_COLOR, GRAPHIC_OUTPUT_BOLD, false);
  iaInput = new StandartLog("iaInput", stdout, IA_INPUT_COLOR, IA_INPUT_BOLD, true);
  iaOutput = new StandartLog("iaOutput", stdout, IA_OUTPUT_COLOR, IA_OUTPUT_BOLD, true);
  intern = new StandartLog("intern", stdout, INTERN_COLOR, INTERN_BOLD, false);
  events = new StandartLog("events", stdout, THREADING_COLOR, THREADING_BOLD, true);
  connection = new StandartLog("connection", stdout, CONNECTION_COLOR, CONNECTION_BOLD, true);
  error = new StandartLog("error", stderr, ERROR_COLOR, ERROR_BOLD, true);
  this->initTabs();
}

void
LogManager::initConsoleLogs()
{
  debug = new ConsoleLog("debug", DEBUG_COLOR, DEBUG_BOLD, false);
  input = new ConsoleLog("input", INPUT_COLOR, INPUT_BOLD, true);
  output = new ConsoleLog("output", OUTPUT_COLOR, OUTPUT_BOLD, true);
  graphicInput = new ConsoleLog("graphicInput", GRAPHIC_INPUT_COLOR, GRAPHIC_INPUT_BOLD, false);
  graphicOutput = new ConsoleLog("graphicOutput", GRAPHIC_OUTPUT_COLOR, GRAPHIC_OUTPUT_BOLD, false);
  iaInput = new ConsoleLog("iaInput", IA_INPUT_COLOR, IA_INPUT_BOLD, true);
  iaOutput = new ConsoleLog("iaOutput", IA_OUTPUT_COLOR, IA_OUTPUT_BOLD, true);
  intern = new ConsoleLog("intern", INTERN_COLOR, INTERN_BOLD, false);
  events = new ConsoleLog("events", THREADING_COLOR, THREADING_BOLD, true);
  connection = new ConsoleLog("connection", CONNECTION_COLOR, CONNECTION_BOLD, true);
  error = new ConsoleLog("error", ERROR_COLOR, ERROR_BOLD, true);
  this->initTabs();
}

void
LogManager::initTabs()
{
  m_logs[ 0] = debug;
  m_logs[ 1] = input;
  m_logs[ 2] = output;
  m_logs[ 3] = graphicInput;
  m_logs[ 4] = graphicOutput;
  m_logs[ 5] = iaInput;
  m_logs[ 6] = iaOutput;
  m_logs[ 7] = intern;
  m_logs[ 8] = events;
  m_logs[ 9] = connection;
  m_logs[10] = error;
  m_logs[11] = NULL;
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
    if (!strcmp(m_logs[index]->getName(), name))
      log = m_logs[index];

  return (log);
}
