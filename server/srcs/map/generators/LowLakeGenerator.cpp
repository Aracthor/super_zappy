//
// LowLakeGenerator.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Mon Oct 27 17:50:55 2014 
// Last Update Tue Oct 28 15:20:25 2014 
//

#include "abstractions/allocs.hh"
#include "map/generators/LowLakeGenerator.hh"

#include <cstring>
#include <cstdio>

LowLakeGenerator::LowLakeGenerator(unsigned int width, unsigned int height) :
  AGenerator(width, height)
{
}

LowLakeGenerator::~LowLakeGenerator()
{
  free(m_oceanHooplas);
}


void
LowLakeGenerator::makeOcean(const Position& position,
			    DisposableQueue<Position>& positionsToTry)
{
  if (position.x >= 0 && position.y >= 0 &&
      position.x < (int)m_width && position.y < (int)m_height &&
      this->getHoopla(position).height / 10.0f <= MIN_HEIGHT &&
      m_oceanHooplas[position.y * m_width + position.x] == false)
    {
      m_oceanHooplas[position.y * m_width + position.x] = true;
      positionsToTry.push(position + Position( 1,  0));
      positionsToTry.push(position + Position(-1,  0));
      positionsToTry.push(position + Position( 0,  1));
      positionsToTry.push(position + Position( 0, -1));
    }
}

void
LowLakeGenerator::testLake(const Position& position)
{
  if (this->getHoopla(position).height / 10.0f <= MIN_HEIGHT &&
      m_oceanHooplas[position.y * m_width + position.x] == false)
    this->getHoopla(position).ground = Hoopla::lake;
}

void
LowLakeGenerator::makeOceans()
{
  DisposableQueue<Position>	m_positionsToTry(m_hooplasNumber * 4);

  m_positionsToTry.push(Position(0, 0));
  while (m_positionsToTry.isEmpty() == false)
    {
      this->makeOcean(m_positionsToTry.accessFront(), m_positionsToTry);
      m_positionsToTry.pop();
    }
}

void
LowLakeGenerator::emplLowLakes()
{
  Position	position;

  MALLOC(m_oceanHooplas, m_hooplasNumber, bool);
  memset(m_oceanHooplas, 0, m_hooplasNumber * sizeof(bool));
  this->makeOceans();

  for (position.x = 0; position.x < (int)m_width; ++position.x)
    for (position.y = 0; position.y < (int)m_height; ++position.y)
      this->testLake(position);
}
