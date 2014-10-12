package Data;

import org.lwjgl.util.vector.Vector3f;

import Debug.DebugLog;

public enum EGround
{
	SNOW(0, new Vector3f(0.9f, 0.9f, 0.9f)),
	BARE(1, new Vector3f(0.5f, 0.5f, 0.5f)),
	TUNDRA(2, new Vector3f(0.7f, 0.7f, 0.7f)),
	TAIGA(3, new Vector3f(0.4f, 1.0f, 0.4f)),
	SHRUBLAND(4, new Vector3f(0.6f, 1.0f, 0.6f)),
	ROCKY_DESERT(5, new Vector3f(0.8f, 0.6f, 0.0f)),
	TEMPERATE_JUNGLE(6, new Vector3f(0.0f, 0.8f, 0.0f)),
	TEMPERATE_FOREST(7, new Vector3f(0.4f, 0.8f, 0.0f)),
	TALLGRASS(8, new Vector3f(0.4f, 1.0f, 0.0f)),
	GRASSLAND(9, new Vector3f(0.6f, 1.0f, 0.3f)),
	PLAIN(10, new Vector3f(0.8f, 1.0f, 0.0f)),
	DESERT(11, new Vector3f(1.0f, 1.0f, 0.4f)),
	TROPICAL_JUNGLE(12, new Vector3f(0.0f, 0.4f, 0.0f)),
	TROPICAL_FOREST(13, new Vector3f(0.0f, 0.6f, 0.0f)),
	BREACH(14, new Vector3f(1.0f, 1.0f, 0.0f)),
	OCEAN(15, new Vector3f(0.0f, 0.0f, 1.0f));
	
	private final int		id;
	private final Vector3f	color;
	
	private EGround(int id, Vector3f color)
	{
		this.id = id;
		this.color = color;
	}
	
	
	public static EGround	getFromId(int id)
	{
		EGround	found;
		
		found = null;
		for (EGround ground : EGround.values())
		{
			if (ground.id == id)
			{
				found = ground;
			}
		}
		
		if (found == null)
		{
			DebugLog.getInstance().err.print("Ground error : No ground found for Id " + id + ".");
		}
		
		return (found);
	}
	
	
	public Vector3f	getColor()
	{
		return (color);
	}
}
