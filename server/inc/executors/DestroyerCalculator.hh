//
// DestroyerCalculator.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Nov  9 09:47:09 2014 
// Last Update Wed Nov 12 10:02:24 2014 
//

#ifndef DESTROYER_CALCULATOR_HH_
# define DESTROYER_CALCULATOR_HH_

# include "IExecutor.hh"
# include "Movements.hh"
# include "map/Hoopla.hh"

class		DestroyerCalculator : public IExecutor
{
private:
  Movements	m_movements;

public:
  DestroyerCalculator();
  ~DestroyerCalculator();

private:
  int	calcTime(Player* player, unsigned char objectId);

public:
  void	execute(Player* player, const Action::UData& data);
};

#endif // !DESTROYER_CALCULATOR_HH_
