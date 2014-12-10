//
// PlayerLocater.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Tue Dec  9 13:06:50 2014 
// Last Update Tue Dec  9 13:17:31 2014 
//

#ifndef PLAYER_LOCATER_HH_
# define PLAYER_LOCATER_HH_

# include "IExecutor.hh"

class	PlayerLocater : public IExecutor
{
public:
  PlayerLocater();
  ~PlayerLocater();

private:
  const Player*	locateClosestEnnemy(const Player* player) const;
  void		sendAnswer(Player* player, const Player* target) const;

public:
  void	execute(Player* player, const Action::UData& data);
};

#endif // !PLAYER_LOCATER_HH_
