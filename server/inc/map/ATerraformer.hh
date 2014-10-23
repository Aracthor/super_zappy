//
// ATerraformer.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Wed Oct 22 14:16:39 2014 
// Last Update Wed Oct 22 14:31:19 2014 
//

#ifndef ATERRAFORMER_HH_
# define ATERRAFORMER_HH_

# include "GroundGenerator.hh"
# include "init/Configs.hh"

# include <ctime>

class	ATerraformer : public GroundGenerator
{
protected:
  Configs::Map	m_configs;

protected:
  Hoopla*	m_hooplas;

public:
  ATerraformer(const Configs::Map& configs);
  virtual ~ATerraformer();

public:
  virtual void	createMap(unsigned long seed = time(NULL)) = 0;

public:
  inline const Hoopla&	getHoopla(unsigned int x, unsigned int y) const;
};

# include "ATerraformer.hpp"

#endif // !ATERRAFORMER_HH_
