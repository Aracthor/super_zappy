//
// Buffer.hpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Mon Oct 20 14:37:12 2014 
// Last Update Wed Oct 22 10:40:44 2014 
//

#include <cstring>

template <unsigned int SIZE>
Buffer<SIZE>::Buffer() :
  m_size(0)
{
  memset(m_data, 0, SIZE);
}

template <unsigned int SIZE>
Buffer<SIZE>::Buffer(const char* data) :
  m_size(strlen(data))
{
  memset(m_data, 0, SIZE);
  strcpy(m_data, data);
}

template <unsigned int SIZE>
Buffer<SIZE>::~Buffer()
{
}


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
const char*
Buffer<SIZE>::getData() const
{
  return (m_data);
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
