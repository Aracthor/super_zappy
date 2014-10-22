//
// Terraformer.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Oct 12 08:10:48 2014 
// Last Update Sun Oct 12 08:32:02 2014 
//

#ifndef TERRAFORMER_HH_
# define TERRAFORMER_HH_

# include <ctime>

# include "Hoopla.hh"
# include "init/Configs.hh"

class	Terraformer
{
private:
  Configs::Map	m_configs;

private:
  Hoopla*	m_hooplas;

public:
  Terraformer(const Configs::Map& configs);
  ~Terraformer();

public:
  void	createMap(unsigned long seed = time(NULL));

public:
  const Hoopla&	getHoopla(unsigned int x, unsigned int y);
};

#endif // !TERRAFORMER_HH_
