package Events;

import org.lwjgl.util.vector.Vector3f;

import Engine.Mesh;

public class MapMoveDownListener extends AStrategicMapListener
{
	public	MapMoveDownListener(Mesh map)
	{
		super(map);
	}
	
	@Override
	public boolean hear(long elapsedTime)
	{
		this.map.translate(new Vector3f(0.0f, elapsedTime, 0.0f));
		return true;
	}

}
