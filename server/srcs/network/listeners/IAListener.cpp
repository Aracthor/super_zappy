//
// IAListener.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Mon Oct 20 14:27:00 2014 
// Last Update Tue Oct 21 10:04:40 2014 
//

#include "network/listeners/IAListener.hh"

IAListener::IAListener()
{
}

IAListener::~IAListener()
{
}


bool
IAListener::listenFromClient(Client* client, char* message)
{
  (void)(client);
  (void)(message);
  return (true);
}
