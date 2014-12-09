//
// Catalog.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Fri Nov 14 11:05:49 2014 
// Last Update Fri Dec  5 16:59:38 2014 
//

#ifndef CATALOG_HH_
# define CATALOG_HH_

# define CONFIGURATION_FOLDER	"configurations"

# include "catalogs/ReadableFromZCSV.hh"

template <class T, unsigned int N>
class	Catalog
{
private:
  T	m_data[N];
  bool	m_exist[N];

public:
  Catalog(const char* file);
  virtual ~Catalog();

private:
  void			readFile(const char* file);

protected:
  void			insert(const T& elem, unsigned int pos);
  inline T&		accessElem(unsigned int index);

public:
  bool			getSecureElem(T& ref, unsigned int index) const;

public:
  inline const T&	getElem(unsigned int index) const;
  inline unsigned int	getSize() const;

public:
  inline const T&       operator[](unsigned int index) const;
};

# include "Catalog.hpp"

#endif // !CATALOG_HH_
