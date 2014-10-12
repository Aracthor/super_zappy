package Events;

import Engine.Camera2D;

public class Camera2DMoveRightListener extends ACamera2DListener
{
	public	Camera2DMoveRightListener(Camera2D camera)
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
