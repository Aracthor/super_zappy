//
// Mutex.hpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Oct 12 10:33:22 2014 
// Last Update Sun Oct 12 10:34:31 2014 
//

bool
Mutex::trylock()
{
  return (pthread_mutex_trylock(&m_mutex));
}
