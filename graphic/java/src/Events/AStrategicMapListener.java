package Events;

import Engine.Mesh;

public abstract class AStrategicMapListener implements IListener
{
	protected	final Mesh	map;
	
	public	AStrategicMapListener(Mesh map)
	{
		this.map = map;
	}
}
