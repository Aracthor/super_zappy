//
// DisposableQueue.hpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Tue Oct 28 15:04:30 2014 
// Last Update Mon Nov  3 16:12:30 2014 
//

#include "abstractions/allocs.hh"

template <typename T>
DisposableQueue<T>::DisposableQueue(unsigned int size) :
  m_size(size)
{
  MALLOC(m_data, size, T);
  this->reset();
}

template <typename T>
DisposableQueue<T>::~DisposableQueue()
{
  free(m_data);
}


template <typename T>
void
DisposableQueue<T>::push(const T& elem)
{
  m_data[m_endIndex] = elem;
  ++m_endIndex;
}

template <typename T>
void
DisposableQueue<T>::pop()
{
  ++m_beginIndex;
}

template <typename T>
const T&
DisposableQueue<T>::accessFront() const
{
  return (m_data[m_beginIndex]);
}

template <typename T>
const T&
DisposableQueue<T>::accessBack() const
{
  return (m_data[m_endIndex]);
}

template <typename T>
bool
DisposableQueue<T>::isEmpty() const
{
  return (m_beginIndex == m_endIndex);
}


template <typename T>
void
DisposableQueue<T>::reset()
{
  m_beginIndex = 0;
  m_endIndex = 0;
}
