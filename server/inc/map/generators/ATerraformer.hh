//
// ATerraformer.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Wed Oct 22 14:16:39 2014 
// Last Update Sun Oct 26 01:21:56 2014 
//

#ifndef ATERRAFORMER_HH_
# define ATERRAFORMER_HH_

# include "GroundGenerator.hh"
# include "ObjectGenerator.hh"
# include "init/Configs.hh"

class	ATerraformer : public GroundGenerator,
		       public ObjectGenerator
{
protected:
  Configs::Map	m_configs;

protected:
  Hoopla*	m_hooplas;
  unsigned int	m_hooplasNumber;

public:
  ATerraformer(const Configs::Map& configs);
  virtual ~ATerraformer();

public:
  virtual void	createMap() = 0;

public:
  inline const Hoopla&	getHoopla(unsigned int x, unsigned int y) const;
};

# include "ATerraformer.hpp"

#endif // !ATERRAFORMER_HH_
