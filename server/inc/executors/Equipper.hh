//
// Equipper.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Wed Nov 12 17:42:04 2014 
// Last Update Wed Dec 10 10:54:10 2014 
//

#ifndef EQUIPPER_HH_
# define EQUIPPER_HH_

# include "IExecutor.hh"
# include "catalogs/WeaponCatalog.hh"

class		Equipper : public IExecutor
{
private:
  WeaponCatalog	m_catalog;

public:
  Equipper();
  ~Equipper();

private:
  Equipement*	createEquipement(Hoopla::EItem item) const;

private:
  bool	unequipe(Player* player);
  bool	changeEquipement(Player* player, Hoopla::EItem item);

public:
  void	execute(Player* player, const Action::UData& data);
};

#endif // !EQUIPPER_HH_
