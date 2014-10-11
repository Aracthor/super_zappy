package Events;

import org.lwjgl.util.vector.Vector3f;

import Engine.Mesh;

public class MapMoveLeftListener extends AStrategicMapListener
{
	public	MapMoveLeftListener(Mesh map)
	{
		super(map);
	}
	
	@Override
	public boolean hear(long elapsedTime)
	{
		this.map.translate(new Vector3f(elapsedTime, 0.0f, 0.0f));
		return true;
	}

}
