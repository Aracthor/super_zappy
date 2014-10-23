package Events;

import Engine.HelicopterCamera;

public class HelicopterCameraRotateRightListener extends AHelicopterCameraListener
{
	public HelicopterCameraRotateRightListener(HelicopterCamera camera)
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
