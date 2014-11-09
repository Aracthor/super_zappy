package Events.Camera2D;

import Engine.Camera.ACamera;
import Engine.Camera.Camera2D;
import Events.IListener;

public abstract class ACamera2DListener implements IListener
{
	protected	final Camera2D	camera;
	
	public	ACamera2DListener(ACamera camera)
	{
		this.camera = (Camera2D)camera;
	}
}
