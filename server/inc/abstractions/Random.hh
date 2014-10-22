//
// Random.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Oct 12 05:42:39 2014 
// Last Update Sun Oct 12 08:27:23 2014 
//

#ifndef RANDOM_HH_
# define RANDOM_HH_

class		Random
{
private:
  unsigned long	m_seed;

public:
  Random(unsigned long seed);
  ~Random();

public:
  unsigned int	getNumber();
};

#endif // !RANDOM_HH_
