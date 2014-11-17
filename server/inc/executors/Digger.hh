//
// Digger.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Fri Nov 14 17:35:58 2014 
// Last Update Fri Nov 14 17:37:08 2014 
//

#ifndef DIGGER_HH_
# define DIGGER_HH_

# include "IExecutor.hh"
# include "catalogs/GroundCatalog.hh"

class		Digger : public IExecutor
{
private:
  GroundCatalog	m_catalog;

public:
  Digger();
  ~Digger();

public:
  void	execute(Player* player, const Action::UData& data);
};

#endif // !DIGGER_HH_
