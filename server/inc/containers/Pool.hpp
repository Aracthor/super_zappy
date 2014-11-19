//
// Pool.hpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Mon Oct 13 17:33:17 2014 
// Last Update Tue Nov 18 16:05:50 2014 
//

#include "abstractions/allocs.hh"
#include "exceptions/ZappyException.hh"

#include <cstring>

template <typename T>
Pool<T>::Pool(unsigned int maxSize) :
  m_size(0),
  m_maxSize(maxSize)
{
  MALLOC(m_data, maxSize, T);
}

template <typename T>
Pool<T>::~Pool()
{
  this->clear();

  free(m_data);
}


template <typename T>
void
Pool<T>::tryToPush() const
{
  if (m_size == m_maxSize)
    throw ZappyException("Trying to push into a full pool.");
}


template <typename T>
void
Pool<T>::pushFront(const T& elem)
{
  this->tryToPush();

  memmove(&m_data[1], &m_data[0], m_size * sizeof(T));
  m_data[0] = elem;
  ++m_size;
}

template <typename T>
void
Pool<T>::pushAt(const T& elem, unsigned int pos)
{
  if (pos >= m_size)
    this->pushBack(elem);
  else
    {
      this->tryToPush();

      memmove(&m_data[pos + 1], &m_data[pos], (m_size - pos) * sizeof(T));
      m_data[pos] = elem;
      ++m_size;
    }
}

template <typename T>
void
Pool<T>::pushBack(const T& elem)
{
  this->tryToPush();

  m_data[m_size] = elem;
  ++m_size;
}


template <typename T>
void
Pool<T>::popFront()
{
  if (this->isEmpty())
    throw ZappyException("popFront in an empty pool.");

  m_data[0].~T();
  memmove(&m_data[0], &m_data[1], (m_size - 1) * sizeof(T));
  --m_size;
}

template <typename T>
void
Pool<T>::popAt(unsigned int pos)
{
  if (pos >= m_size)
    throw ZappyException("popAt too far.");

  m_data[pos].~T();
  if (pos < m_size - 1)
    memmove(&m_data[pos], &m_data[pos + 1], (m_size - pos - 1) * sizeof(T));
  --m_size;
}

template <typename T>
void
Pool<T>::popElem(const T* elem)
{
  unsigned int	pos;

  pos = static_cast<unsigned int>(elem - m_data);
  if (pos > m_maxSize)
    throw ZappyException("Invalid pool popElem.");

  m_data[pos].~T();
  if (pos < m_size - 1)
    memmove(&m_data[pos], &m_data[pos + 1], (m_size - pos - 1) * sizeof(T));
  --m_size;
}

template <typename T>
void
Pool<T>::popBack()
{
  if (this->isEmpty())
    throw ZappyException("popBack in an empty pool.");

  m_data[m_size - 1].~T();
  --m_size;
}


template <typename T>
void
Pool<T>::clear()
{
  unsigned int	i;

  FOREACH_IN_POOL(i)
  {
    m_data[i].~T();
  }
  m_size = 0;
}


template <typename T>
void
Pool<T>::forEach(void (T::*method)())
{
  unsigned int	i;

  FOREACH_IN_POOL(i)
  {
    (m_data[i].*method)();
  }
}


template <typename T>
bool
Pool<T>::isEmpty() const
{
  return (m_size == 0);
}

template <typename T>
unsigned int
Pool<T>::getSize() const
{
  return (m_size);
}

template <typename T>
unsigned int
Pool<T>::getMaxSize() const
{
  return (m_maxSize);
}

template <typename T>
const T&
Pool<T>::front() const
{
  return (m_data[0]);
}

template <typename T>
T&
Pool<T>::front()
{
  return (m_data[0]);
}

template <typename T>
const T&
Pool<T>::back() const
{
  return (m_data[m_size - 1]);
}

template <typename T>
T&
Pool<T>::back()
{
  return (m_data[m_size - 1]);
}


template <typename T>
const T&
Pool<T>::operator[](unsigned int index) const
{
  return (m_data[index]);
}

template <typename T>
T&
Pool<T>::operator[](unsigned int index)
{
  return (m_data[index]);
}
