//
// NamesRegister.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Fri Dec  5 14:22:25 2014 
// Last Update Fri Dec  5 15:46:25 2014 
//

#ifndef NAMES_REGISTER_HH_
# define NAMES_REGISTER_HH_

# include <string>

# include "Hoopla.hh"
# include "usefull/Singleton.hh"

class		NamesRegister
{
private:
  const char*	m_grounds[Hoopla::grounds_number];
  const char*	m_items[Hoopla::items_number];
  const char*	m_objects[Hoopla::objects_number];

private:
  NamesRegister();
  ~NamesRegister();

private:
  void	initGrounds();
  void	initItems();
  void	initObjects();

private:
  int	search(const char* const* names, const char* name, int names_number) const;

public:
  int		getFromName(const char* name) const;
  inline int	getFromName(const std::string& name) const;

public:
  inline const char*	operator[](Hoopla::EGround grounds) const;
  inline const char*	operator[](Hoopla::EItem item) const;
  inline const char*	operator[](Hoopla::EObject objects) const;

  friend class	Singleton<NamesRegister>;
};

typedef Singleton<NamesRegister>	NamesRegisterSingleton;

# include "NamesRegister.hpp"

#endif // !NAMES_REGISTER_HH_
