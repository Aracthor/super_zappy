//
// Destroyer.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Nov  9 09:46:46 2014 
// Last Update Thu Dec  4 10:45:32 2014 
//

#ifndef DESTROYER_HH_
# define DESTROYER_HH_

# include "IExecutor.hh"
# include "catalogs/ObjectCatalog.hh"
# include "map/Hoopla.hh"

class		Destroyer : public IExecutor
{
private:
  ObjectCatalog m_catalog;

public:
  Destroyer();
  ~Destroyer();

public:
  void	execute(Player* player, const Action::UData& data);
};

#endif // !DESTROYER_HH_
