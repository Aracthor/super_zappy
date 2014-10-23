package Events;

import Engine.Camera2D;

public class Camera2DMoveDownListener extends ACamera2DListener
{
	public	Camera2DMoveDownListener(Camera2D camera)
	{
		super(camera);
	}
	
	@Override
	public boolean hear(long elapsedTime)
	{
		this.camera.move(0.0f, elapsedTime);
		return true;
	}

}