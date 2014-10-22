//
// Chunk.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Oct 12 07:45:39 2014 
// Last Update Sun Oct 12 08:52:46 2014 
//

#include "map/Chunk.hh"

Chunk::Chunk()
{
}

Chunk::~Chunk()
{
}


void
Chunk::setHoopla(const Hoopla& hoopla, unsigned int x, unsigned int y)
{
  m_hooplas[y][x] = hoopla;
}
