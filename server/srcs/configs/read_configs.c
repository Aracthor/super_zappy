/*
** read_configs.c for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
** 
** Made by 
** Login   <aracthor@epitech.net>
** 
** Started on  Sat Oct  4 21:56:49 2014 
** Last Update Sun Oct  5 00:08:42 2014 
*/

#include <stddef.h>

#include "configs.h"
#include "exception.h"

static void	init_configs(s_configs* configs)
{
  configs->port = CONFIGS_DEFAULT_PORT;
  configs->speed = CONFIGS_DEFAULT_SPEED;
  configs->map.longer = CONFIGS_DEFAULT_LONGER;
  configs->map.larger = CONFIGS_DEFAULT_LARGER;
  configs->teams.names = NULL;
  configs->teams.number = 0;
}

static void	empl_flags_tabs(t_param_reader* readers, char* flags)
{
  readers[0] = &change_port;
  readers[1] = &change_speed;
  readers[2] = &change_map_longer;
  readers[3] = &change_map_larger;
  readers[4] = &add_team_name;

  flags[0] = 'p';
  flags[1] = 's';
  flags[2] = 'x';
  flags[3] = 'y';
  flags[4] = 'n';
}

static t_param_reader	change_reader(char flag)
{
  t_param_reader	readers[FLAGS_NUMBER];
  char			flags[FLAGS_NUMBER];
  unsigned int		i;
  t_param_reader	new_reader;

  empl_flags_tabs(readers, flags);
  new_reader = NULL;

  for (i = 0; i < FLAGS_NUMBER && new_reader == NULL; ++i)
    if (flags[i] == flag)
      new_reader = readers[i];

  if (new_reader == NULL)
    throw (exception_bad_flag);

  return (new_reader);
}

static void	read_arg(char* arg, s_configs* configs, t_param_reader* reader)
{
  if (arg[0] == '-')
    *reader = change_reader(arg[1]);
  else if (*reader == NULL)
    throw (exception_bad_flag);
  else
    (*reader)(arg, configs);
}

void			read_configs(int argc, char** argv, s_configs* configs)
{
  t_param_reader	reader;
  int			i;

  init_configs(configs);
  reader = NULL;
  for (i = 1; i < argc; ++i)
    read_arg(argv[i], configs, &reader);

  if (configs->teams.number < TEAMS_NUMBER_MIN)
    throw (exception_not_enough_teams);
}
