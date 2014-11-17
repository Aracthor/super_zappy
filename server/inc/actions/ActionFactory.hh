//
// ActionFactory.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sat Nov  8 23:00:05 2014 
// Last Update Fri Nov 14 14:33:14 2014 
//

#ifndef ACTION_FACTORY_HH_
# define ACTION_FACTORY_HH_

# include "Action.hh"
# include "network/listeners/CommandCutter.hh"
# include "timecalcs/ITimeCalculator.hh"

class		ActionFactory
{
private:
  typedef bool	(ActionFactory::*DataReader)(Action::UData& data,
					     const CommandCutter::CuttedLine& args) const;

private:
  const char*		m_actionNames[Action::actions_number];
  unsigned int		m_actionTimers[Action::actions_number];
  DataReader		m_actionReaders[Action::actions_number];
  ITimeCalculator*	m_timeCalcs[Action::actions_number];

public:
  ActionFactory();
  virtual ~ActionFactory();

private:
  bool	readPositionData(Action::UData& data, const CommandCutter::CuttedLine& args) const;
  bool	readIdData(Action::UData& data, const CommandCutter::CuttedLine& args) const;
  bool	readItemData(Action::UData& data, const CommandCutter::CuttedLine& args) const;
  bool	readTextData(Action::UData& data, const CommandCutter::CuttedLine& args) const;

public:
  bool	createAction(Action& action, const char* actionName, Player* player,
		     const CommandCutter::CuttedLine& args);
};

#endif // !ACTION_FACTORY_HH_
