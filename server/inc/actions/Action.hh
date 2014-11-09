//
// Action.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sat Nov  8 19:34:56 2014 
// Last Update Sun Nov  9 08:09:38 2014 
//

#ifndef ACTION_HH_
# define ACTION_HH_

# include "data/Player.hh"

# include <SFML/System/Vector2.hpp>

# define MAX_WAITING_ACTIONS	(200)

class	Action
{
public:
  enum	EAction
    {
      displace,
      move,
      rotate,
      search,
      actions_number
    };

  union UData
  {
    struct		Pos
    {
      unsigned int	x;
      unsigned int	y;
    };

    UData() {}
    UData(bool boolean) {this->boolean = boolean;}

    Pos			position;
    unsigned int        id;
    bool		boolean;
  };

private:
  Player*		m_player;
  EAction		m_action;
  UData			m_data;
  int			m_timer;

public:
  Action();
  Action(Player* player, EAction action, int time, const UData& data = UData());
  Action(Player* player, EAction action, int time, bool boolean);
  ~Action();

public:
  Action&		operator=(const Action& copy);

public:
  inline void		setTimer(int timer);
  inline void		decrementTimer();
  inline Player*	getPlayer();

  inline EAction	getAction() const;
  inline const Player*	getPlayer() const;
  inline const UData&	getData() const;
  inline int		getTimer() const;
};

# include "Action.hpp"

#endif // !ACTION_HH_
