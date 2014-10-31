//
// ObjectGenerator.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Oct 26 00:57:15 2014 
// Last Update Tue Oct 28 14:01:07 2014 
//

#ifndef OBJECT_GENERATOR_HH_
# define OBJECT_GENERATOR_HH_

# include "map/Hoopla.hh"

class	ObjectGenerator
{
private:
  typedef unsigned int	ObjectProbabilities[Hoopla::grounds_number][Hoopla::objects_number];

private:
  Hoopla::EObject	m_object[Hoopla::grounds_number][100];

public:
  ObjectGenerator();
  virtual ~ObjectGenerator();

private:
  Hoopla::EObject	getObject(unsigned char) const;

public:
  void	setObjects(Hoopla* hooplas, unsigned int number) const;

private:
  void	readObjectConfigs(ObjectProbabilities* probabilities);
};

#endif // !OBJECT_GENERATOR_HH_
