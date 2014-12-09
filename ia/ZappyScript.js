//
// Script.js for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/ia
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Thu Nov  6 14:27:41 2014 
// Last Update Tue Dec  9 12:36:14 2014 
//

load("Items.js");
load("Mail.js");
load("Objects.js");
load("Target.js")
load("Vector.js");

function	ScriptExit()
{
}


function	ZappyScript()
{
    this.ring = new java.util.concurrent.locks.ReentrantLock(true);
    this.ring.lock();
    this.messages = [];
}

ZappyScript.prototype.copy = function()
{
    script = new ZappyScript;

    script.start = this.start;
    script.play = this.play;

    for (var attr in this)
    {
        if (this.hasOwnProperty(attr))
	{
	    script[attr] = this[attr];
	}
    }

    return (script);
}

ZappyScript.prototype.start = function()
{
    var	waiting;
    var message;

    this.loop = true;
    waiting = true;

    while (waiting)
    {
	message = this.waitForAnswer("START");
	if (message[0] == "true")
	{
	    waiting = false;
	}
    }

    try
    {
	this.play();
    }
    catch (exception)
    {
    }
}


ZappyScript.prototype.dring = function()
{
    this.ring.unlock();
    this.ring.lock();
}

ZappyScript.prototype.stop = function()
{
    this.loop = false;
    this.dring();
}


ZappyScript.prototype.sendMessage = function(message)
{
    this.messages.push(message);
    this.dring();
}

ZappyScript.prototype.receiveFriendMessage = function(message)
{
    var mail;

    mail = new Mail(message);
    this.onFriendMessage(mail);
}

ZappyScript.prototype.readUnexpectedMessage = function(message)
{
    if (message[0] == "FRIEND_MESSAGE" && this.onFriendMessage != null)
    {
	message.shift();
	this.receiveFriendMessage(message);
    }
    else
    {
	// I don't give a shit yo !
    }
}

ZappyScript.prototype.waitForAnswer = function(wanted)
{
    var	answer;
    var message;

    answer = null;

    while (this.loop == true && answer == null)
    {
	if (this.messages.length > 0)
	{
	    message = this.messages[0];
	    this.messages.shift();
	    if (message[0] == wanted)
	    {
		message.shift();
		answer = message;
	    }
	    else
	    {
		this.readUnexpectedMessage(message);
	    }
	}
	else
	{
	    this.ring.lock();
	    this.ring.unlock();
	}
    }

    if (this.loop == false)
    {
	throw new ScriptExit;
    }

    return (answer);
}

ZappyScript.prototype.waitConfirmation = function()
{
    var	answer;

    answer = this.waitForAnswer("END");

    return (answer[0] == "true");
}

ZappyScript.prototype.waitItems = function()
{
    var answer = this.waitForAnswer("ITEMS");
    var	items;

    if (answer[0] == "NULL")
    {
	items = null;
    }
    else
    {
	items = new Items(parseInt(answer[0]), parseInt(answer[1]));
    }

    return (items);
}

ZappyScript.prototype.waitItem = function()
{
    var answer = this.waitForAnswer("ITEM");
    var	item;

    if (answer[0] == "NULL")
    {
	item = null;
    }
    else
    {
	item = new Item(parseInt(answer[0]));
    }

    return (item);
}


ZappyScript.prototype.getItemId = function(item)
{
    var	id;

    if (isInt(item))
    {
	id = item;
    }
    else
    {
	id = item.id;
    }

    return (id);
}


ZappyScript.prototype.displace = function(x, y)
{
    client.send("DIS " + this.player.name + ' ' + x + ' ' + y);
    return (this.waitConfirmation());
}

ZappyScript.prototype.search = function(object)
{
    var	answer;
    var	found;

    client.send("SRH " + this.player.name + ' ' + object.id);
    answer = this.waitForAnswer("OBJECT");

    if (answer[0] == "NULL")
    {
	found = null;
    }
    else
    {
	found = new Object(parseInt(answer[0]));
	found.position.x = parseInt(answer[1]);
	found.position.y = parseInt(answer[2]);
    }

    return (found);
}

ZappyScript.prototype.destroy = function(x, y)
{
    client.send("DES " + this.player.name + ' ' + x + ' ' + y);
    return (this.waitConfirmation());
}

ZappyScript.prototype.dig = function()
{
    client.send("DIG " + this.player.name);
    return (this.waitItem());
}

ZappyScript.prototype.take = function()
{
    client.send("TAK " + this.player.name);
    return (this.waitItems());
}

ZappyScript.prototype.put = function(id, number)
{
    client.send("PUT " + this.player.name + ' ' + id + ' ' + number);
    return (this.waitConfirmation());
}

ZappyScript.prototype.equip = function(item)
{
    var id;

    id = this.getItemId(item);
    client.send("EQU " + this.player.name + ' ' + id);
    return (this.waitConfirmation());
}

ZappyScript.prototype.craft = function(item)
{
    var	id;

    id = this.getItemId(item);
    client.send("CRF " + this.player.name + ' ' + id);
    return (this.waitConfirmation());
}

ZappyScript.prototype.sendMail = function(message)
{
    client.send("MAIL " + this.player.name + ' ' + message);
    return (true);
}

ZappyScript.prototype.locateEnnemy = function(name)
{
    var	string;
    var	answer;
    var	found;

    string = "LEN " + this.player.name;
    if (name != null)
    {
	string += ' ' + name;
    }
    client.send(string);
    answer = this.waitForAnswer("PLAYER");

    if (answer[0] == "NULL")
    {
	found = null;
    }
    else
    {
	found = new Target(parseInt(answer[0]));
	found.position.x = parseInt(answer[1]);
	found.position.y = parseInt(answer[2]);
    }

    return (found);
}

ZappyScript.prototype.locateClosestEnnemy = function()
{
    return (this.locateEnnemy(null));
}


ZappyScript.prototype.wait = function()
{
    this.waitForAnswer("YOLO");
}
