//
// Crafter.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Fri Nov 14 10:37:19 2014 
// Last Update Fri Nov 14 12:24:10 2014 
//

#ifndef CRAFTER_HH_
# define CRAFTER_HH_

# include "IExecutor.hh"
# include "catalogs/CraftCatalog.hh"

class		Crafter : public IExecutor
{
private:
  CraftCatalog	m_catalog;

public:
  Crafter();
  ~Crafter();

public:
  void	execute(Player* player, const Action::UData& data);
};

#endif // !CRAFTER_HH_
