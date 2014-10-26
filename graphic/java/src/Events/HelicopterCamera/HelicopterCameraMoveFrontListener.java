package Events.HelicopterCamera;

import Engine.Camera.HelicopterCamera;

public class HelicopterCameraMoveFrontListener extends AHelicopterCameraListener
{
	public HelicopterCameraMoveFrontListener(HelicopterCamera camera)
	{
		super(camera);
	}
	
	@Override
	public boolean hear(long elapsedTime)
	{
		camera.avance(elapsedTime);
		
		return true;
	}
}
