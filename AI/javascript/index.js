//
// main.js for test in /home/aracthor/programs/projects/hub/super_zappy/ia
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Fri Oct 31 10:37:17 2014 
// Last Update Thu Nov  6 14:52:42 2014 
//

try
{
    arguments.unshift("rhino index.js");
    load("main.js");
    main(arguments.length, arguments);
}
catch (error)
{
    print("\033[01;31m" + error.message + "\033[0m");
}
