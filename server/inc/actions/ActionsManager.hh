//
// ActionsManager.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sat Nov  8 20:24:10 2014 
// Last Update Sun Nov  9 03:19:28 2014 
//

#ifndef ACTIONS_MANAGER_HH_
# define ACTIONS_MANAGER_HH_

# include "Action.hh"
# include "containers/Pool.hh"
# include "threading/Mutex.hh"

class	ActionsManager
{
public:
  typedef Pool<Action>	ActionsList;

private:
  ActionsList	m_actions;
  Mutex		m_lock;
  unsigned int	m_executionSpeed;

public:
  ActionsManager(unsigned int speed);
  virtual ~ActionsManager();

public:
  void	insertAction(Action action);

public:
  inline const ActionsList&	getActions() const;
  inline ActionsList&		getActions();
  inline unsigned int		getSpeed() const;

  inline void			lockActions();
  inline void			unlockActions();
};

# include "ActionsManager.hpp"

#endif // !ACTIONS_MANAGER_HH_
