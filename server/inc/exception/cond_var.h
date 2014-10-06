/*
** cond_var.h<2> for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
** 
** Made by 
** Login   <aracthor@epitech.net>
** 
** Started on  Sun Oct  5 04:27:50 2014 
** Last Update Sun Oct  5 04:28:45 2014 
*/

#ifndef EXCEPTION_COND_VAR_H_
# define EXCEPTION_COND_VAR_H_

typedef enum	exception_cond_var
{
  exception_cond_var_create,
  exception_cond_var_delete,
  exception_cond_var_signal,
  exception_cond_var_wait,
  exceptions_cond_var_number
}		e_exception_cond_var;

/* cond_var.c */
int	exception_cond_var_handling(unsigned short arg);

#endif /* !EXCEPTION_COND_VAR_H_ */
