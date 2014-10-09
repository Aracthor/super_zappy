/*
** action.h for super_zappy in /home/aracthor/programs/projects/hub/super_zappy
** 
** Made by 
** Login   <aracthor@epitech.net>
** 
** Started on  Wed Oct  8 10:36:18 2014 
** Last Update Wed Oct  8 13:53:21 2014 
*/

#ifndef ACTION_H_
# define ACTION_H_

typedef unsigned int	t_action_arg;

typedef struct	action
{
  unsigned int	id;
  t_action_arg	arg;
  unsigned int	remaining_time;
}		s_action;

/* create.c */
void	create_action(s_action* action, unsigned int id,
		      t_action_arg arg, unsigned int remaining_time);

#endif /* !ACTION_H_ */
