//
// Buffer.hpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Mon Nov 17 09:00:58 2014 
// Last Update Tue Nov 18 08:32:22 2014 
//

#include "abstractions/maths.hh"

#include <cstring>

template <unsigned int SIZE>
void
Buffer<SIZE>::popFront(unsigned int size)
{
  m_size -= size;
  memmove(m_data, &m_data[size], m_size);
  m_data[m_size] = '\0';
}

template <unsigned int SIZE>
void
Buffer<SIZE>::popAt(unsigned int index)
{
  memmove(&m_data[index], &m_data[index + 1], m_size - index - 1);
  --m_size;
  m_data[m_size] = '\0';
}

template <unsigned int SIZE>
void
Buffer<SIZE>::insertAt(const char data, unsigned int index)
{
  memmove(&m_data[index + 1], &m_data[index], m_size - index);
  m_data[index] = data;
  ++m_size;
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
  m_data[0] = '\0';
}

template <unsigned int SIZE>
void
Buffer<SIZE>::reset()
{
  m_size = 0;
  memset(m_data, 0, SIZE);
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
