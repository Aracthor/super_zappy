package Events.Camera2D;

import Engine.Camera.Camera2D;
import Events.IListener;

public abstract class ACamera2DListener implements IListener
{
	protected	final Camera2D	camera;
	
	public	ACamera2DListener(Camera2D camera)
	{
		this.camera = camera;
	}
}
