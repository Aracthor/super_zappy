//
// KingScript.js for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/ia
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Thu Nov  6 14:00:21 2014 
// Last Update Mon Jul 20 13:09:03 2015 Aracthor
//

function	KingScript()
{
}

KingScript.prototype = new ZappyScript;


function	yieldForNothing(mail)
{
    print("There is " + mail.from + " who told me '" + mail.data + "' ! ");
}

KingScript.prototype.play = function()
{
    this.onFriendMessage = yieldForNothing;
    wait();
}
