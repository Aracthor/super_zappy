package Events.HelicopterCamera;

import Engine.Camera.HelicopterCamera;

public class HelicopterCameraRotateLeftListener extends AHelicopterCameraListener
{
	public HelicopterCameraRotateLeftListener(HelicopterCamera camera)
	{
		super(camera);
	}
	
	@Override
	public boolean hear(long elapsedTime)
	{
		camera.rotate(elapsedTime);
		
		return true;
	}
}
