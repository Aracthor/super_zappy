#!/usr/bin/python3
## main.py for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/ia/python
## 
## Made by aracthor
## Login   <aracthor@epitech.net>
## 
## Started on  Tue Feb 24 09:27:39 2015 aracthor
## Last Update Tue Feb 24 12:32:29 2015 aracthor
##

import  sys

from    Client          import Client
from    Colors          import Colors
from    Configs         import Configs
from    Exceptions      import ZappyException
from    Team            import Team

def     main(argc, argv):
    try:
        configs = Configs(argc, argv)
        team = Team(configs.script)
        client = Client.create(configs.host, configs.port)
        client.sendTeamDetails(team, configs.name)
        client.disconnect()
        return_value = 0

    except ZappyException as exception:
        sys.stderr.write(Colors.BOLD + Colors.RED + "ZAPPY ERROR: " + exception.what() + ".\n" + Colors.NORMAL)
        return_value = 1

    except Exception as exception:
        sys.stderr.write(Colors.BOLD + Colors.RED + "FATAL ERROR: " + format(exception) + "\n" + Colors.NORMAL)
        return_value = 2

    except:
        sys.stderr.write(Colors.BOLD + Colors.RED + "FATAL UNKNOW ERROR\n" + Colors.NORMAL)
        return_value = 3

    return (return_value)

if __name__ == "__main__":
    sys.exit(main(len(sys.argv), sys.argv))
