//
// Catalog.hpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Fri Nov 14 11:07:21 2014 
// Last Update Tue Dec  9 09:41:04 2014 
//

#include <fstream>

#include "exceptions/FileException.hh"
#include "map/NamesRegister.hh"

#include <cstring>

template <class T, unsigned int N>
Catalog<T, N>::Catalog(const char* file)
{
  memset(m_exist, false, sizeof(m_exist));
  this->readFile(file);
}

template <class T, unsigned int N>
Catalog<T, N>::~Catalog()
{
}


template <class T, unsigned int N>
void
Catalog<T, N>::readFile(const char* file)
{
  std::ifstream	stream((std::string(CONFIGURATION_FOLDER) + '/' + file + ".zcsv").c_str());
  std::string	line;
  unsigned int	pos;
  unsigned int	elemId;
  T		elem;

  if (stream.good() == false)
    throw FileException(file, "Cannot open file.");

  while (std::getline(stream, line))
    {
      pos = line.find(DEFINITION_CHAR);
      if (pos == std::string::npos)
	throw FileException(file, "Corrupted file : missing definition token");
      elemId = NamesRegisterSingleton::access()->getFromName(line.substr(0, pos));

      elem.readFromString(line, pos + 1);
      this->insert(elem, elemId);
    }
}

template <class T, unsigned int N>
void
Catalog<T, N>::insert(const T& elem, unsigned int pos)
{
  m_data[pos] = elem;
  m_exist[pos] = true;
}

template <class T, unsigned int N>
T&
Catalog<T, N>::accessElem(unsigned int index)
{
  return (m_data[index]);
}


template <class T, unsigned int N>
bool
Catalog<T, N>::getSecureElem(T& ref, unsigned int index) const
{
  if (m_exist[index])
    ref = m_data[index];
  return (m_exist[index]);
}


template <class T, unsigned int N>
const T&
Catalog<T, N>::getElem(unsigned int index) const
{
  return (m_data[index]);
}

template <class T, unsigned int N>
unsigned int
Catalog<T, N>::getSize() const
{
  return (N);
}


template <class T, unsigned int N>
const T&
Catalog<T, N>::operator[](unsigned int index) const
{
  return (this->getElem(index));
}
