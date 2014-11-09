package Events.HelicopterCamera;

import Engine.Camera.ACamera;

public class HelicopterCameraMoveBackListener extends AHelicopterCameraListener
{
	public HelicopterCameraMoveBackListener(ACamera camera)
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
