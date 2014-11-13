//
// Player.js for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/ia/scripts
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Mon Nov  3 17:20:56 2014 
// Last Update Wed Nov 12 14:16:04 2014 
//

function	Execution(player, script)
{
    this.player = player;
    this.script = script;
    this.script.player = player;
}

Execution.prototype.run = function()
{
    client.send(EAction.playerDescription + ' ' + this.player.name + ' ' + this.player.type);
    this.script.start();
}


function	Player(name, type)
{
    this.name = name;
    this.type = type;
}

Player.prototype.setScript = function(script)
{
    this.script = script.copy();
    this.runnable = new java.lang.Runnable(new Execution(this, this.script));
    this.thread = new java.lang.Thread(this.runnable);
}


Player.prototype.play = function()
{
    this.thread.start();
}

Player.prototype.interrupt = function()
{
    this.thread.interrupt();
}
