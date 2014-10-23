package Events;

import Engine.HelicopterCamera;

public abstract class AHelicopterCameraListener implements IListener
{
	protected final HelicopterCamera	camera;
	
	public	AHelicopterCameraListener(HelicopterCamera camera)
	{
		this.camera = camera;
	}
}
