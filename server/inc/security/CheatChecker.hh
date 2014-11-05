//
// CheatChecker.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Tue Nov  4 13:22:41 2014 
// Last Update Tue Nov  4 13:58:20 2014 
//

#ifndef CHEAT_CHECKER_HH_
# define CHEAT_CHECKER_HH_

# include "StatChecker.hh"
# include "util/Singleton.hh"

class	CheatChecker;

typedef Singleton<CheatChecker>	CheatCheckerSingleton;

class	CheatChecker : public StatChecker
{
private:
  CheatChecker();
  ~CheatChecker();

  friend class	Singleton<CheatChecker>;
};

#endif // !CHEAT_CHECKER_HH_
