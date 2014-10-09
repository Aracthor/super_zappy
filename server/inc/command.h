/*
** command.h for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
** 
** Made by 
** Login   <aracthor@epitech.net>
** 
** Started on  Tue Oct  7 09:32:33 2014 
** Last Update Wed Oct  8 14:05:50 2014 
*/

#ifndef COMMAND_H_
# define COMMAND_H_

# include "action.h"
# include "boolean.h"

# define MAX_ARGS_NUMBER	(5)

# define ARGS_DELIMITER		(" ")

# define GRAPHICAL_ORDERS_NUMBER	(4)
# define IA_ORDERS_NUMBER		(1)
# define GRAPHICAL_COMMANDS_NUMBER	(7)
# define IA_COMMANDS_NUMBER		(1)

# define SERVER_WELCOME		("WELCOME")
# define GRAPHICAL_MESSAGE	("GRAPHICAL")
# define IA_MESSAGE		("IA")
# define SERVER_KICK		("GET THE FUCK OUT")

# define IA_BAD_ORDER		("YOU CAN'T BITCH")


typedef struct	args
{
  char*		data[MAX_ARGS_NUMBER];
  unsigned int	number;
}		s_args;

typedef bool	(*t_graphical_command)(const void* server, const s_args* args, char* line);
typedef bool	(*t_ia_command)(const void* server, const s_args* args, s_action* action);

typedef struct  order
{
  char*		code;
  unsigned int	args_number;
  unsigned int	command_id;
}		s_order;

typedef enum	graphical_code
{
  chunk_description,
  case_description,
  player_description,
  player_equipement,
  player_taking,
  player_putting,
  team_description
}		e_graphical_code;

/* access.c */
int	find_order_id(const s_order* orders, const s_args* args);

/* create.c */
void	create_order(s_order* order, char* code, unsigned int args_number, unsigned int id);

/* cut_line_in_args.c */
bool	cut_line_in_args(char* line, s_args* args);

#endif /* !COMMAND_H_ */
