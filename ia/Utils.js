//
// Utils.js for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/ia
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Wed Nov 12 17:36:50 2014 
// Last Update Wed Nov 12 17:37:07 2014 
//

function isInt(value)
{
    return (!isNaN(value) && 
            parseInt(Number(value)) == value && 
            !isNaN(parseInt(value, 10)));
}
