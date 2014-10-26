package Events.Camera2D;

import Engine.Camera.Camera2D;

public class Camera2DZoomFrontListener extends ACamera2DListener
{
	public	Camera2DZoomFrontListener(Camera2D camera)
	{
		super(camera);
	}
	
	@Override
	public boolean hear(long elapsedTime)
	{
		this.camera.zoom(0.9f);
		return true;
	}
}
