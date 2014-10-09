/*
** teams.h for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
** 
** Made by 
** Login   <aracthor@epitech.net>
** 
** Started on  Sun Oct  5 02:31:46 2014 
** Last Update Tue Oct  7 16:58:06 2014 
*/

#ifndef TEAMS_H_
# define TEAMS_H_

# include "boolean.h"
# include "command.h"

typedef struct	teams
{
  char**        names;
  unsigned int	number;
}		s_teams;

/* access.c */
int	get_team_id(const s_teams* teams, char* team);

#endif /* !TEAMS_H_ */
