//
// main.js for test in /home/aracthor/programs/projects/hub/super_zappy/ia
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Fri Oct 31 10:37:17 2014 
// Last Update Mon Nov  3 18:05:09 2014 
//

load("main.js");

try
{
    arguments.unshift("rhino index.js");
    main(arguments.length, arguments);
}
catch (error)
{
    print("\033[01;31m" + error.message + "\033[0m");
}
