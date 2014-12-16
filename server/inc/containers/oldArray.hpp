//
// Array.hpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Tue Nov  4 10:40:17 2014 
// Last Update Tue Nov 18 15:17:20 2014 
//

#include "abstractions/allocs.hh"

template <typename T>
Array<T>::Array() :
  m_maxSize(0),
  m_size(0),
  m_data(NULL)
{
}

template <typename T>
Array<T>::~Array()
{
  this->free();
}


template <typename T>
void
Array<T>::resize(unsigned int size)
{
  REALLOC(m_data, size, T);
  m_maxSize = size;
}

template <typename T>
void
Array<T>::free()
{
  unsigned int	i;

  if (m_data != NULL)
    {
      for (i = 0; i < m_size; ++i)
	m_data[i].destroy();

      ::free(m_data);
    }
      
  m_data = NULL;
  m_size = 0;
}


template <typename T>
void
Array<T>::push(const T& elem)
{
  m_data[m_size] = elem;
  ++m_size;
}

template <typename T>
bool
Array<T>::securePush(const T& elem)
{
  bool	secure;

  secure = !this->isFull();
  if (secure)
    this->push(elem);

  return (secure);
}


template <typename T>
bool
Array<T>::isFull() const
{
  return (m_size == m_maxSize);
}

template <typename T>
unsigned int
Array<T>::getSize() const
{
  return (m_size);
}

template <typename T>
const T*
Array<T>::getData() const
{
  return (m_data);
}

template <typename T>
T*
Array<T>::getData()
{
  return (m_data);
}


template <typename T>
void
Array<T>::operator<<(const T& elem)
{
  this->push(elem);
}

template <typename T>
const T&
Array<T>::operator[](unsigned int id) const
{
  return (m_data[id]);
}

template <typename T>
T&
Array<T>::operator[](unsigned int id)
{
  return (m_data[id]);
}
