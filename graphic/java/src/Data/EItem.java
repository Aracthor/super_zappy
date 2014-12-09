package Data;

import Debug.DebugLog;
import Engine.Models.Mesh;
import Graphics.GraphicWarehouse;

public enum EItem
{
	None(0, null),
	SnowBall(1, null),
	Pebble(2, null),
	FrostPlant(3, null),
	Mud(4, null),
	TemperatePlant(5, null),
	Grass(6, null),
	Sand(7, null),
	TropicalPlant(8, null),
	FreshWater(9, null),
	IceBlock(10, null),
	Water(11, null),
	Stick(12, "stick"),
	Log(13, "log"),
	WoodenJavelin(14, "wooden javelin");
	
	private int		id;
	private String	name;
	private Mesh	model2D;
	private Mesh	model3D;
	
	private EItem(int id, String name)
	{
		this.id = id;
		this.name = name;
		this.model2D = null;
		this.model3D = GraphicWarehouse.getInstance().getModel(name);
	}
	
	
	public static EItem	getFromId(int id)
	{
		EItem	found;
		
		found = null;
		for (EItem Item : EItem.values())
		{
			if (Item.id == id)
			{
				found = Item;
			}
		}
		
		if (found == null)
		{
			DebugLog.getInstance().err.print("Item error : No Item found for Id " + id + ".");
		}
		
		return (found);
	}
	
	public String	getName()
	{
		return (name);
	}
	
	public Mesh	get2DModel()
	{
		return (model2D);
	}
	
	public Mesh	get3DModel()
	{
		return (model3D);
	}
}
