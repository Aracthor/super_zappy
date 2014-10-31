//
// Terraformer.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Oct 12 08:10:48 2014 
// Last Update Sun Oct 26 10:30:10 2014 
//

#ifndef TERRAFORMER_HH_
# define TERRAFORMER_HH_

# include "ATerraformer.hh"

class	Terraformer : public ATerraformer
{
public:
  Terraformer(const Configs::Map& configs);
  ~Terraformer();

private:
  void	calcHeights();

public:
  void	createMap();
};

#endif // !TERRAFORMER_HH_
