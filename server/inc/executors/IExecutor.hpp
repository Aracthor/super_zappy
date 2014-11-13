//
// IExecutor.hpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Wed Nov 12 09:19:50 2014 
// Last Update Wed Nov 12 09:20:32 2014 
//

void
IExecutor::insertAction(const Action& action)
{
  this->getServerData()->insertAction(action);
}
