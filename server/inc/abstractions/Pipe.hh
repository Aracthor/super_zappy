//
// Pipe.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Tue Nov 18 08:01:51 2014 
// Last Update Tue Nov 18 08:22:39 2014 
//

#ifndef PIPE_HH_
# define PIPE_HH_

class		Pipe
{
public:
  typedef int	fd;

private:
  fd		m_fd[2];
  bool		m_open[2];

public:
  Pipe();
  ~Pipe();

private:
  void		closeFd(int id);

public:
  inline void	closeInput();
  inline void	closeOutput();

public:
  inline fd	getInput() const;
  inline fd	getOutput() const;

public:
  template <typename T>
  void	operator<<(const T& elem) const;
  template <typename T>
  void	operator>>(T& elem) const;
};

# include "Pipe.hpp"

#endif // !PIPE_HH_
