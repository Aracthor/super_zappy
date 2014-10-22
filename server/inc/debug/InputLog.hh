//
// InputLog.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Mon Oct 20 09:01:14 2014 
// Last Update Mon Oct 20 09:04:37 2014 
//

#ifndef INPUT_LOG_HH_
# define INPUT_LOG_HH_

# include <ostream>

class	InputLog
{
public:
  InputLog();
  ~InputLog();

public:
  template <typename T>
  std::ostream&	operator<<(std::ostream& stream, const T& message);
};

#endif // !INPUT_LOG_HH_
