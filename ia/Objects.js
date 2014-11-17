//
// Objects.js for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/ia
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Sun Nov  9 07:41:29 2014 
// Last Update Fri Nov 14 10:33:48 2014 
//

load("Vector.js");

function	Object(id)
{
    this.id = id;
    this.position = new Vector;
}

function	Objects()
{
    this.nothing	= new Object(0);
    this.bush		= new Object(1);
    this.shrub		= new Object(2);
    this.oak		= new Object(3);
    this.ash		= new Object(4);
    this.saplin		= new Object(5);
    this.maple		= new Object(6);
    this.player		= new Object(7);
}

var	g_objects = new Objects;
