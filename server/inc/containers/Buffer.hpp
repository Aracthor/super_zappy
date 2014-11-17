//
// Buffer.hpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Mon Nov 17 09:00:58 2014 
// Last Update Mon Nov 17 12:27:11 2014 
//

#include "abstractions/maths.hh"

#include <cstring>

template <unsigned int SIZE>
void
Buffer<SIZE>::popFront(unsigned int size)
{
  m_size -= size;
  memmove(m_data, &m_data[size], m_size);
}

template <unsigned int SIZE>
void
Buffer<SIZE>::pushBack(const char data)
{
  m_data[m_size] = data;
  ++m_size;
}

template <unsigned int SIZE>
void
Buffer<SIZE>::pushBack(const char* data, unsigned int size)
{
  memcpy(&m_data[m_size], data, size);
  m_size += size;
}

template <unsigned int SIZE>
void
Buffer<SIZE>::pushBack(const char* data)
{
  this->pushBack(data, strlen(data));
}


template <unsigned int SIZE>
template <unsigned int N>
void
Buffer<SIZE>::copyFrom(const Buffer<N>& buffer)
{
  unsigned int	size;

  size = MIN(buffer.getSize(), this->getRemainingSize());
  this->pushBack(buffer.getData(), size);
}


template <unsigned int SIZE>
void
Buffer<SIZE>::addToSize(unsigned int size)
{
  m_size += size;
}


template <unsigned int SIZE>
bool
Buffer<SIZE>::isEmpty() const
{
  return (m_size == 0);
}

template <unsigned int SIZE>
unsigned int
Buffer<SIZE>::getSize() const
{
  return (m_size);
}

template <unsigned int SIZE>
unsigned int
Buffer<SIZE>::getRemainingSize() const
{
  return (SIZE - m_size);
}

template <unsigned int SIZE>
const char*
Buffer<SIZE>::getData() const
{
  return (m_data);
}

template <unsigned int SIZE>
const char*
Buffer<SIZE>::getEnd() const
{
  return (m_data + m_size);
}

template <unsigned int SIZE>
void
Buffer<SIZE>::clear()
{
  m_size = 0;
}

template <unsigned int SIZE>
char*
Buffer<SIZE>::getData()
{
  return (m_data);
}

template <unsigned int SIZE>
char*
Buffer<SIZE>::getEnd()
{
  return (m_data + m_size);
}
