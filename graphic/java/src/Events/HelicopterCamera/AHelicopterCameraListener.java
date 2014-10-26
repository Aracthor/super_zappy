package Events.HelicopterCamera;

import Engine.Camera.HelicopterCamera;
import Events.IListener;

public abstract class AHelicopterCameraListener implements IListener
{
	protected final HelicopterCamera	camera;
	
	public	AHelicopterCameraListener(HelicopterCamera camera)
	{
		this.camera = camera;
	}
}
