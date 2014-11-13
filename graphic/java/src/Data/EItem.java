package Data;

import Debug.DebugLog;
import Engine.Models.Mesh;
import Graphics.GraphicWarehouse;

public enum EItem
{
	None(0, null),
	Stick(1, "stick");
	
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
