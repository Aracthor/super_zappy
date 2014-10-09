/*
** param.h for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
** 
** Made by 
** Login   <aracthor@epitech.net>
** 
** Started on  Sun Oct  5 01:33:41 2014 
** Last Update Wed Oct  8 11:00:06 2014 
*/

#ifndef EXCEPTION_PARAM_H_
# define EXCEPTION_PARAM_H_

# define IS_USAGE_EXCEPTION(e)	(e >= exception_bad_flag && e <= exception_not_enough_teams) 

typedef enum	exception_param_arg
{
  exception_param_port,
  exception_param_speed,
  exception_param_teams,
  exception_param_map_longer,
  exception_param_map_larger,
  exceptions_param_number
}		e_exception_param_arg;

/* params.c */
int	exception_bad_flag_handling(unsigned short arg);
int	exception_bad_param_handling(unsigned short arg);
int	exception_bad_param_arg_handling(unsigned short arg);
int	exception_not_enough_teams_handling(unsigned short arg);

#endif /* !EXCEPTION_PARAM_H_ */
