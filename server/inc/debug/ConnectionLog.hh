//
// ConnectionLog.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Mon Oct 20 09:01:14 2014 
// Last Update Mon Oct 20 09:05:10 2014 
//

#ifndef CONNECTION_LOG_HH_
# define CONNECTION_LOG_HH_

# include <ostream>

class	ConnectionLog
{
public:
  ConnectionLog();
  ~ConnectionLog();
};

template <typename T>
std::ostream&	operator<<(std::ostream& stream, const T& message);

#endif // !CONNECTION_LOG_HH_
