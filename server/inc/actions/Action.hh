//
// Action.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sat Nov  8 19:34:56 2014 
// Last Update Fri Dec  5 08:57:33 2014 
//

#ifndef ACTION_HH_
# define ACTION_HH_

# include "map/Hoopla.hh"

# include <SFML/System/Vector2.hpp>

# define MAX_WAITING_ACTIONS	(200)
# define MAIL_BUFFER_SIZE	(0x100)

class	Player;

class	Action
{
public:
  enum	EAction
    {
      displace,
      move,
      rotate,
      search,
      destroy,
      dig,
      take,
      put,
      equip,
      craft,
      build,
      mail,
      actions_number
    };

  union			UData
  {
    struct		Pos
    {
      unsigned int	x;
      unsigned int	y;
    };
    struct	        Item
    {
      Hoopla::EItem	id;
      unsigned int	number;
    };

    UData() {}
    UData(bool boolean) {this->boolean = boolean;}

    Pos			position;
    Item		item;
    unsigned int	id;
    bool		boolean;
    char		text[MAIL_BUFFER_SIZE];
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
