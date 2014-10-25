//
// ATerraformer.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Wed Oct 22 14:16:39 2014 
// Last Update Fri Oct 24 17:16:21 2014 
//

#ifndef ATERRAFORMER_HH_
# define ATERRAFORMER_HH_

# include "GroundGenerator.hh"
# include "init/Configs.hh"

class	ATerraformer : public GroundGenerator
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
