//
// LogParameter.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Tue Nov 18 10:15:17 2014 
// Last Update Tue Nov 18 10:59:39 2014 
//

#ifndef LOG_PARAMETER_HH_
# define LOG_PARAMETER_HH_

# include "Log.hh"
# include "core/AExecuter.hh"

class	LogParameter : public AExecuter
{
private:
  Log*	m_workingLog;

public:
  LogParameter();
  virtual ~LogParameter();

private:
  void	active(const char* params);
  void	disactive(const char* params);

public:
  void	executeLogCommand(const char* command, const char* logName, const char* params);
};

#endif // !LOG_PARAMETER_HH_
