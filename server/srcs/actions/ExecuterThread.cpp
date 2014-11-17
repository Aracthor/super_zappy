//
// ExecuterThread.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sat Nov  8 20:20:00 2014 
// Last Update Sun Nov 16 16:05:54 2014 
//

#include "actions/ExecuterThread.hh"
#include "core/Server.hh"
#include "debug/LogManager.hh"
#include "executors/Crafter.hh"
#include "executors/Destroyer.hh"
#include "executors/Digger.hh"
#include "executors/Displacer.hh"
#include "executors/Equipper.hh"
#include "executors/Mailer.hh"
#include "executors/Mover.hh"
#include "executors/Putter.hh"
#include "executors/Rotater.hh"
#include "executors/Searcher.hh"
#include "executors/Taker.hh"

#include <unistd.h>

ExecuterThread::ExecuterThread() :
  AZappyThread("Executer"),
  m_loopCounter(0)
{
  m_executors[Action::displace]		= new Displacer;
  m_executors[Action::move]		= new Mover;
  m_executors[Action::rotate]		= new Rotater;
  m_executors[Action::search]		= new Searcher;
  m_executors[Action::destroy]		= new Destroyer;
  m_executors[Action::dig]		= new Digger;
  m_executors[Action::take]		= new Taker;
  m_executors[Action::put]		= new Putter;
  m_executors[Action::equip]		= new Equipper;
  m_executors[Action::craft]		= new Crafter;
  m_executors[Action::build]		= NULL;
  m_executors[Action::mail]		= new Mailer;
}

ExecuterThread::~ExecuterThread()
{
  unsigned int	i;

  for (i = 0; i < Action::actions_number; ++i)
    delete (m_executors[i]);
}


void
ExecuterThread::decrementTimers()
{
  ActionsManager::ActionsList&	actions = m_server->getActions();

  actions.forEach(&Action::decrementTimer);
}

void
ExecuterThread::executeActions()
{
  ActionsManager::ActionsList&	actions = m_server->getActions();
  IExecutor*			executor;

  while (actions.isEmpty() == false && actions.front().getTimer() <= 0)
    {
      executor = m_executors[actions.front().getAction()];
      LogManagerSingleton::access()->intern->print("Executing action %d for player %s.",
						   actions.front().getAction(),
						   actions.front().getPlayer()->getName());
      if (executor == NULL)
	LogManagerSingleton::access()->error->print("Executor for action %d is TODO !",
						    actions.front().getAction());
      else
	executor->execute(actions.front().getPlayer(), actions.front().getData());
      actions.popFront();
    }
}


void
ExecuterThread::execute()
{
  long	timeToWait;

  m_clock.update();
  {
    m_server->lockClients();
    m_server->lockActions();
    {
      this->executeActions();
      this->decrementTimers();
    }
    m_server->unlockActions();
    m_server->unlockClients();
  }
  m_clock.update();
  timeToWait = static_cast<long>(this->getServerData()->getSpeed());
  timeToWait -= static_cast<long>(m_clock.getElapsedTime());

  if (timeToWait < 0)
    LogManagerSingleton::access()->error->print("Warning : loop longer than speed !");
  else
    usleep(timeToWait);
}

void
ExecuterThread::incrementLoop()
{
  if (m_loopCounter * this->getServerData()->getSpeed() / 10000 % 10 == 0)
    LogManagerSingleton::access()->intern->print("Cycle %d.", m_loopCounter);
  ++m_loopCounter;
}


bool
ExecuterThread::loopCycle()
{
  this->execute();
  this->incrementLoop();
  m_server->getSpeakRing().signal();

  return (true);
}
