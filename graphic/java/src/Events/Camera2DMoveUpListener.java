package Events;

import Engine.Camera2D;

public class Camera2DMoveUpListener extends ACamera2DListener
{
	public	Camera2DMoveUpListener(Camera2D camera)
	{
		super(camera);
	}
	
	@Override
	public boolean hear(long elapsedTime)
	{
		this.camera.move(0.0f, -elapsedTime);
		return true;
	}

}
