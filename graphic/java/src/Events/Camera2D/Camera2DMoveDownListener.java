package Events.Camera2D;

import Engine.Camera.ACamera;

public class Camera2DMoveDownListener extends ACamera2DListener
{
	public	Camera2DMoveDownListener(ACamera camera)
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
