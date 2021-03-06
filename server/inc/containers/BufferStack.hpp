//
// BufferStack.hpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Mon Oct 20 14:37:12 2014 
// Last Update Mon Nov 17 09:01:25 2014 
//

#include "abstractions/allocs.hh"

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
Buffer<SIZE>::Buffer(const Buffer& copy) :
  m_size(copy.m_size)
{
  strcpy(m_data, copy.m_data);
}

template <unsigned int SIZE>
Buffer<SIZE>::~Buffer()
{
}

template <unsigned int SIZE>
Buffer<SIZE>&
Buffer<SIZE>::operator=(const Buffer& copy)
{
  m_size = copy.m_size;
  strcpy(m_data, copy.m_data);

  return *this;
}
