//
// KingScript.js for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/ia
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Thu Nov  6 14:00:21 2014 
// Last Update Wed Dec 17 12:38:06 2014 
//

function	KingScript()
{
}

KingScript.prototype = new ZappyScript;


function	gueulerPourRien(mail)
{
    print("Y'a " + mail.from + " qui me dit '" + mail.data + "' ! ");
}

KingScript.prototype.play = function()
{
    this.onFriendMessage = gueulerPourRien;
    wait();
}
