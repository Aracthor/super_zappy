package Events.Camera2D;

import Engine.Camera.ACamera;

public class Camera2DZoomBackListener extends ACamera2DListener
{
	public	Camera2DZoomBackListener(ACamera camera)
	{
		super(camera);
	}
	
	@Override
	public boolean hear(long elapsedTime)
	{
		this.camera.zoom(1.1f);
		return true;
	}
}
