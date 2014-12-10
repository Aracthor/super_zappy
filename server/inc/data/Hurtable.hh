//
// Hurtable.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Tue Dec  9 12:50:35 2014 
// Last Update Wed Dec 10 10:42:47 2014 
//

#ifndef HURTABLE_HH_
# define HURTABLE_HH_

class	Hurtable
{
protected:
  int   m_maxLife;
  int	m_currentLife;

public:
  Hurtable(unsigned int life);
  virtual ~Hurtable();

public:
  virtual void	hurt(unsigned int damages);
  virtual void	heal(unsigned int healing);

public:
  inline unsigned int	getMaxLife() const;
  inline unsigned int	getCurrentLife() const;
  inline bool		isAlive() const;
  inline bool		isDead() const;
};

# include "Hurtable.hpp"

#endif // !HURTABLE_HH_
