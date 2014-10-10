package Events;

import Engine.Camera2D;

public abstract class ACamera2DListener implements IListener
{
	protected	final Camera2D	camera;
	
	public	ACamera2DListener(Camera2D camera)
	{
		this.camera = camera;
	}
}
