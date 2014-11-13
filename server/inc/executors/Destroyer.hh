//
// Destroyer.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Nov  9 09:46:46 2014 
// Last Update Wed Nov 12 10:02:00 2014 
//

#ifndef DESTROYER_HH_
# define DESTROYER_HH_

# include "IExecutor.hh"
# include "Movements.hh"
# include "map/Hoopla.hh"

class			Destroyer : public IExecutor
{
private:
  typedef void	(Destroyer::*ObjectDestroyer)(const Player* player, Hoopla* hoopla);

private:
  ObjectDestroyer	m_destroyers[Hoopla::objects_number];
  Movements		m_movements;

public:
  Destroyer();
  ~Destroyer();

private:
  bool	getHoopla(const Player* player, Hoopla** hoopla, unsigned char id);

private:
  void	bushDestroyer(const Player* player, Hoopla* hoopla);

public:
  void	execute(Player* player, const Action::UData& data);
};

#endif // !DESTROYER_HH_
