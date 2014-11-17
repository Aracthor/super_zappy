//
// Items.js for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/ia
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Wed Nov 12 13:46:06 2014 
// Last Update Fri Nov 14 17:49:40 2014 
//

function	Items(id, number)
{
    this.id = id;
    this.number = number;
}

function	Item(id, name)
{
    this.id = id;
    this.name = name
}

function		ItemList()
{
    this.none		= new Item( 0, "none");
    this.snowBall	= new Item( 1, "snow ball");
    this.pebble		= new Item( 2, "pebble");
    this.frostPlant	= new Item( 3, "frost plant");
    this.mud		= new Item( 4, "mud");
    this.temperatePlant	= new Item( 5, "temperate plant");
    this.grass		= new Item( 6, "grass");
    this.sand		= new Item( 7, "sand");
    this.tropicalPlant	= new Item( 8, "tropical plant");
    this.freshWater	= new Item( 9, "fresh water");
    this.iceBlock	= new Item(10, "ice block");
    this.water		= new Item(11, "water");
    this.stick		= new Item(12, "stick");
    this.wooden_javelin	= new Item(13, "wooden javelin");
    this.number = 14;
}

var	g_items = new ItemList;
