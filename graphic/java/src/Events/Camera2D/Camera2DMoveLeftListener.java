package Events.Camera2D;

import Engine.Camera.Camera2D;

public class Camera2DMoveLeftListener extends ACamera2DListener
{
	public	Camera2DMoveLeftListener(Camera2D camera)
	{
		super(camera);
	}
	
	@Override
	public boolean hear(long elapsedTime)
	{
		this.camera.move(elapsedTime, 0.0f);
		return true;
	}

}
