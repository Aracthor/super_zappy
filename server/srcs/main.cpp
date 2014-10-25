//
// main.cpp for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Oct 12 05:27:44 2014 
// Last Update Fri Oct 24 17:17:17 2014 
//

#include <iostream>

#include "core/Server.hh"
#include "exceptions/ConfigsException.hh"

#include <cstdlib>
#include <ctime>
#include <unistd.h>

static void	print_usage(char* name)
{
  std::cerr << "Usage : " << name << std::endl
	    << "\t[-x longer]" << std::endl
	    << "\t[-y larger]" << std::endl
	    << "\t[-p port]" << std::endl
	    << "\t[-s speed]" << std::endl
	    << "\t-n team1 team2 {teams}" << std::endl;
}

int		main(int argc, char** argv)
{
  Configs	configs;
  Server*	server;
  int		return_value;

  srandom(time(NULL) * getpid());

  try
    {
      configs.readConfigs(argc, argv);
      server = new Server(configs);
      server->start();
      delete (server);
      return_value = 0;
    }

  catch (const ConfigsException& exception)
    {
      std::cerr << "Configs error : " << exception.what() << std::endl;
      print_usage(argv[0]);
      return_value = 1;
    }

  catch (const std::exception& exception)
    {
      std::cerr << "Fatal error : " << exception.what() << std::endl;
      return_value = 2;
    }

  return (return_value);
}
