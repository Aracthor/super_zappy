package Data;

import Debug.DebugLog;
import Engine.Models.Mesh;
import Graphics.GraphicWarehouse;

public enum EObject
{
	NOTHING(0, null),
	BUSH(1, "bush"),
	SHRUB(2, "shrub"),
	OAK(3, "oak"),
	ASH(4, "ash"),
	SAPLIN(5, "saplin"),
	MAPLE(6, "maple");
	
	private int		id;
	private String	name;
	private Mesh	model2D;
	private Mesh	model3D;
	
	private EObject(int id, String name)
	{
		this.id = id;
		this.name = name;
		this.model2D = GraphicWarehouse.getInstance().getTextureSquare(name);
		this.model3D = GraphicWarehouse.getInstance().getModel(name);
	}
	
	
	public static EObject	getFromId(int id)
	{
		EObject	found;
		
		found = null;
		for (EObject Object : EObject.values())
		{
			if (Object.id == id)
			{
				found = Object;
			}
		}
		
		if (found == null)
		{
			DebugLog.getInstance().err.print("Object error : No Object found for Id " + id + ".");
		}
		
		return (found);
	}
	
	public String	getName()
	{
		return (name);
	}
	
	public Mesh		get2DModel()
	{
		return (model2D);
	}
	
	public Mesh		get3DModel()
	{
		return (model3D);
	}
}
