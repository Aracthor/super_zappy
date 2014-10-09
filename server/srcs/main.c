/*
** main.c for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
** 
** Made by 
** Login   <aracthor@epitech.net>
** 
** Started on  Sat Oct  4 19:19:52 2014 
** Last Update Wed Oct  8 11:04:40 2014 
*/

#include "exception.h"
#include "server.h"

static int	execution(int argc, char** argv)
{
  s_configs	configs;
  s_server	server;

  read_configs(argc, argv, &configs);
  server_init(&server, &configs);
  {
    server_start(&server);
  }
  server_delete(&server);
  return (0);
}

int		main(int argc, char** argv)
{
  t_exception	exception;
  int		return_value;

  try (exception)
    return_value = execution(argc, argv);
  catch (exception)
    return_value = exception_handle(exception, argv[0]);
  return (return_value);
}
