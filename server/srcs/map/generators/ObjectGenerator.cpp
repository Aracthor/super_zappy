//
// ObjectGenerator.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Oct 26 01:01:28 2014 
// Last Update Sun Oct 26 05:02:05 2014 
//

#include "map/generators/ObjectGenerator.hh"

#include <cstdlib>
#include <cstring>

ObjectGenerator::ObjectGenerator()
{
  ObjectProbabilities	probabilities;
  unsigned int		ground;
  unsigned int		object;
  unsigned int		pos;
  unsigned int		i;

  memset(probabilities, 0, sizeof(probabilities));
  this->readObjectConfigs(&probabilities);

  for (ground = 0; ground < Hoopla::grounds_number; ++ground)
    {
      pos = 0;
      for (object = 0; object < Hoopla::objects_number; ++object)
	{
	  for (i = 0; i < probabilities[ground][object]; ++i)
	    {
	      m_object[ground][pos] = static_cast<Hoopla::EObject>(object);
	      ++pos;
	    }
	}
      while (pos < 100)
	{
	  m_object[ground][pos] = Hoopla::nothing;
	  ++pos;
	}
    }
}

ObjectGenerator::~ObjectGenerator()
{
}


Hoopla::EObject
ObjectGenerator::getObject(Hoopla::EGround ground) const
{
  return (m_object[ground][random() % 100]);
}


void
ObjectGenerator::setObjects(Hoopla* hooplas, unsigned int number) const
{
  unsigned int	i;

  for (i = 0; i < number; ++i)
    hooplas[i].object = this->getObject(hooplas[i].ground);
}


void
ObjectGenerator::readObjectConfigs(ObjectProbabilities* probabilities)
{
  (*probabilities)[Hoopla::taiga][Hoopla::shrub] = 20;
  (*probabilities)[Hoopla::taiga][Hoopla::saplin] = 20;
  (*probabilities)[Hoopla::taiga][Hoopla::maple] = 10;

  (*probabilities)[Hoopla::shrubland][Hoopla::shrub] = 25;

  (*probabilities)[Hoopla::temperate_jungle][Hoopla::shrub] = 5;
  (*probabilities)[Hoopla::temperate_jungle][Hoopla::bush] = 10;
  (*probabilities)[Hoopla::temperate_jungle][Hoopla::oak] = 10;
  (*probabilities)[Hoopla::temperate_jungle][Hoopla::ash] = 10;
  (*probabilities)[Hoopla::temperate_jungle][Hoopla::saplin] = 5;
  (*probabilities)[Hoopla::temperate_jungle][Hoopla::maple] = 5;

  (*probabilities)[Hoopla::temperate_forest][Hoopla::shrub] = 8;
  (*probabilities)[Hoopla::temperate_forest][Hoopla::bush] = 3;
  (*probabilities)[Hoopla::temperate_forest][Hoopla::oak] = 8;
  (*probabilities)[Hoopla::temperate_forest][Hoopla::ash] = 8;
  (*probabilities)[Hoopla::temperate_forest][Hoopla::saplin] = 3;
  (*probabilities)[Hoopla::temperate_forest][Hoopla::maple] = 3;

  (*probabilities)[Hoopla::tallgrass][Hoopla::bush] = 5;
  (*probabilities)[Hoopla::tallgrass][Hoopla::shrub] = 2;

  (*probabilities)[Hoopla::grassland][Hoopla::bush] = 3;
  (*probabilities)[Hoopla::grassland][Hoopla::shrub] = 1;

  (*probabilities)[Hoopla::plain][Hoopla::bush] = 1;
  (*probabilities)[Hoopla::plain][Hoopla::shrub] = 1;

  (*probabilities)[Hoopla::tropical_jungle][Hoopla::shrub] = 10;
  (*probabilities)[Hoopla::tropical_jungle][Hoopla::bush] = 15;
  (*probabilities)[Hoopla::tropical_jungle][Hoopla::oak] = 15;
  (*probabilities)[Hoopla::tropical_jungle][Hoopla::ash] = 15;

  (*probabilities)[Hoopla::tropical_forest][Hoopla::shrub] = 5;
  (*probabilities)[Hoopla::tropical_forest][Hoopla::bush] = 10;
  (*probabilities)[Hoopla::tropical_forest][Hoopla::oak] = 15;
  (*probabilities)[Hoopla::tropical_forest][Hoopla::ash] = 15;

  (*probabilities)[Hoopla::marsh][Hoopla::shrub] = 4;
  (*probabilities)[Hoopla::marsh][Hoopla::bush] = 10;
}
