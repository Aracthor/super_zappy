//
// Equipper.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Wed Nov 12 17:42:04 2014 
// Last Update Thu Nov 13 08:38:31 2014 
//

#ifndef EQUIPPER_HH_
# define EQUIPPER_HH_

# include "IExecutor.hh"

class	Equipper : public IExecutor
{
public:
  Equipper();
  ~Equipper();

private:
  bool	unequipe(Player* player);
  bool	changeEquipement(Player* player, Hoopla::EItem item);

public:
  void	execute(Player* player, const Action::UData& data);
};

#endif // !EQUIPPER_HH_
