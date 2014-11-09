package Events.HelicopterCamera;

import Engine.Camera.ACamera;
import Engine.Camera.HelicopterCamera;
import Events.IListener;

public abstract class AHelicopterCameraListener implements IListener
{
	protected final HelicopterCamera	camera;
	
	public	AHelicopterCameraListener(ACamera camera)
	{
		this.camera = (HelicopterCamera)camera;
	}
}
