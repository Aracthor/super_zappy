package Events.Camera2D;

import Engine.Camera.ACamera;

public class Camera2DMoveRightListener extends ACamera2DListener
{
	public	Camera2DMoveRightListener(ACamera camera)
	{
		super(camera);
	}
	
	@Override
	public boolean hear(long elapsedTime)
	{
		this.camera.move(-elapsedTime, 0.0f);
		return true;
	}

}
