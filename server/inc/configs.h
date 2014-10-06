/*
** configs.h for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
** 
** Made by 
** Login   <aracthor@epitech.net>
** 
** Started on  Sat Oct  4 19:51:15 2014 
** Last Update Sun Oct  5 02:31:42 2014 
*/

#ifndef CONFIGS_H_
# define CONFIGS_H_

# include "teams.h"

# define CONFIGS_DEFAULT_PORT	(4242)
# define CONFIGS_DEFAULT_SPEED	(500000)
# define CONFIGS_DEFAULT_LONGER	(16)
# define CONFIGS_DEFAULT_LARGER	(16)

# define PORT_MIN		(0x401)
# define PORT_MAX		(0xFFFF)
# define SPEED_MIN		(1000)
# define SPEED_MAX		(10000000)
# define MAP_SIZE_MIN		(4)
# define MAP_SIZE_MAX		(256)
# define TEAMS_NUMBER_MIN	(2)

# define FLAGS_NUMBER		(5)

typedef struct	map_configs
{
  unsigned int	longer;
  unsigned int	larger;
}		s_map_configs;

typedef struct	configs
{
  unsigned int	port;
  unsigned int	speed;
  s_map_configs	map;
  s_teams	teams;
}		s_configs;


typedef void	(*t_param_reader)(char* arg, s_configs* configs);

/* read_configs.c */
void	read_configs(int argc, char** argv, s_configs* configs);

/* number_params.c */
void	change_port(char* name, s_configs* configs);
void	change_speed(char* name, s_configs* configs);
void	change_map_longer(char* name, s_configs* configs);
void	change_map_larger(char* name, s_configs* configs);

/* string_params.c */
void	add_team_name(char* name, s_configs* configs);

#endif /* !CONFIGS_H_ */
