//
// Searcher.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Nov  9 08:11:52 2014 
// Last Update Sun Nov  9 08:57:06 2014 
//

#ifndef SEARCHER_HH_
# define SEARCHER_HH_

# include <SFML/System/Vector2.hpp>

# include "IExecutor.hh"
# include "Movements.hh"
# include "map/Hoopla.hh"

class	Searcher : public IExecutor,
		   public Movements
{
public:
  Searcher();
  ~Searcher();

private:
  bool	research(sf::Vector2i& position, sf::Vector2i& movement, const sf::Vector2i& origin,
		 unsigned char object, sf::Vector2u& pos, int* ptr);

private:
  bool  upToRight(const sf::Vector2i& origin, int range,
		  unsigned char object, sf::Vector2u& pos);
  bool  rightToDown(const sf::Vector2i& origin, int range,
		    unsigned char object, sf::Vector2u& pos);
  bool  downToLeft(const sf::Vector2i& origin, int range,
		   unsigned char object, sf::Vector2u& pos);
  bool  leftToUp(const sf::Vector2i& origin, int range,
		 unsigned char object, sf::Vector2u& pos);

private:
  bool  lookAtRange(const sf::Vector2i& origin, int range,
		    unsigned char object, sf::Vector2u& pos);
  bool	search(const sf::Vector2i& origin, int range,
	       unsigned char object, sf::Vector2u& pos);

public:
  void	execute(Player* player, const Action::UData& data);

private:
  bool	find(const sf::Vector2i& pos, unsigned char object) const;
};

#endif // !SEARCHER_HH_
