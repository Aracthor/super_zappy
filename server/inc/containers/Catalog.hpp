//
// Catalog.hpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Fri Nov 14 11:07:21 2014 
// Last Update Fri Nov 14 17:11:00 2014 
//

#include <cstring>

template <class T, unsigned int N>
Catalog<T, N>::Catalog()
{
  memset(m_exist, false, sizeof(m_exist));
}

template <class T, unsigned int N>
Catalog<T, N>::~Catalog()
{
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
