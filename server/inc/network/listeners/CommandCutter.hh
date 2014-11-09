//
// CommandCutter.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Tue Oct 21 12:19:36 2014 
// Last Update Sat Nov  8 23:39:17 2014 
//

#ifndef COMMAND_CUTTER_HH_
# define COMMAND_CUTTER_HH_

# include "network/Protocol.hh"

class			CommandCutter
{
public:
  struct		CuttedLine
  {
    char*		args[GRAPHIC_MAX_ARGS_NUMBER];
    unsigned int	argsNumber;
  };

public:
  CommandCutter();
  virtual ~CommandCutter();

public:
  bool	cutInArgs(CuttedLine& cuttedLine, char* line);
};

#endif // !COMMAND_CUTTER_HH_
