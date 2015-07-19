//
// Mail.js for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/ia
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Fri Nov 14 14:06:17 2014 
// Last Update Fri Nov 14 16:30:07 2014 
//

function	Mail(message)
{
    var i;

    this.from = message[0];
    this.data = "";
    for (i = 1; i < message.length - 2; ++i)
    {
	if (i > 1)
	{
	    this.data += " ";
	}
	this.data += message[i];
    }
}
