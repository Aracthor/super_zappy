//
// Terraformer.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Oct 12 08:10:48 2014 
// Last Update Wed Oct 22 14:22:12 2014 
//

#ifndef TERRAFORMER_HH_
# define TERRAFORMER_HH_

# include "ATerraformer.hh"

class	Terraformer : public ATerraformer
{
public:
  Terraformer(const Configs::Map& configs);
  ~Terraformer();

public:
  void	createMap(unsigned long seed = time(NULL));
};

#endif // !TERRAFORMER_HH_
