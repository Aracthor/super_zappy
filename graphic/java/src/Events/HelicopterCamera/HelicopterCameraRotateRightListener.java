package Events.HelicopterCamera;

import Engine.Camera.ACamera;

public class HelicopterCameraRotateRightListener extends AHelicopterCameraListener
{
	public HelicopterCameraRotateRightListener(ACamera camera)
	{
		super(camera);
	}
	
	@Override
	public boolean hear(long elapsedTime)
	{
		camera.rotate(-elapsedTime);
		
		return true;
	}
}
