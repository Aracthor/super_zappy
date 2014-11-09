package Events.HelicopterCamera;

import Engine.Camera.ACamera;

public class HelicopterCameraRotateLeftListener extends AHelicopterCameraListener
{
	public HelicopterCameraRotateLeftListener(ACamera camera)
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
