package Events;

import Engine.HelicopterCamera;

public class HelicopterCameraMoveBackListener extends AHelicopterCameraListener
{
	public HelicopterCameraMoveBackListener(HelicopterCamera camera)
	{
		super(camera);
	}
	
	@Override
	public boolean hear(long elapsedTime)
	{
		camera.avance(-elapsedTime);
		
		return true;
	}
}