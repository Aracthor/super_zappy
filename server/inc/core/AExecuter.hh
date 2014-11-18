//
// AExecuter.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Tue Nov 18 10:20:05 2014 
// Last Update Tue Nov 18 10:46:19 2014 
//

#ifndef AEXECUTER_HH_
# define AEXECUTER_HH_

# define MAX_EXECUTIONS_NUMBER	(2)

class		AExecuter
{
protected:
  typedef void	(AExecuter::*Execution)(const char* params);

protected:
  const char*	m_commands[MAX_EXECUTIONS_NUMBER];
  Execution	m_executions[MAX_EXECUTIONS_NUMBER];
  unsigned int	m_index;

protected:
  AExecuter();
  virtual ~AExecuter();

protected:
  template <class T>
  void		addCommand(const char* name, void (T::*method)(const char* param));

protected:
  const char*	getNextToken(const char* params) const;
  unsigned int	tokenSize(const char* token) const;

private:
  unsigned int	calcCommandSize(const char* command) const;

public:
  void		executeCommand(const char* command);
  void		executeCommand(const char* name, const char* param);
};

# include "AExecuter.hpp"

#endif // !AEXECUTER_HH_
