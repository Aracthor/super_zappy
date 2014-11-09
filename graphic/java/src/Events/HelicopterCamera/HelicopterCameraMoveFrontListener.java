package Events.HelicopterCamera;

import Engine.Camera.ACamera;

public class HelicopterCameraMoveFrontListener extends AHelicopterCameraListener
{
public HelicopterCameraMoveFrontListener(ACamera camera)
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
