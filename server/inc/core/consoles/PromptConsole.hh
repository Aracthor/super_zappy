//
// PromptConsole.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Mon Nov 17 17:02:23 2014 
// Last Update Tue Nov 18 08:29:41 2014 
//

#ifndef PROMPT_CONSOLE_HH_
# define PROMPT_CONSOLE_HH_

# include "Console.hh"
# include "containers/Buffer.hh"

# define PROMPT_MAX_SIZE	(200)

class				PromptConsole : public Console
{
private:
  Buffer<PROMPT_MAX_SIZE>	m_buffer;
  unsigned int			m_index;

public:
  PromptConsole();
  ~PromptConsole();

public:
  void	incrementIndex();
  void	decrementIndex();
  void	addChar(char c);
  void	deleteChar();
  void	clear();

public:
  inline const char*	getInput() const;

public:
  void	update();
  void	drawData() const;
};

# include "PromptConsole.hpp"

#endif // !PROMPT_CONSOLE_HH_
