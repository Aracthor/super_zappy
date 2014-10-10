package Events;

import Engine.Camera2D;
import Engine.Vector2;

public class Camera2DMoveUpListener extends ACamera2DListener
{
	public	Camera2DMoveUpListener(Camera2D camera)
	{
		super(camera);
	}
	
	@Override
	public boolean hear()
	{
		this.camera.move(new Vector2(0.0f, -1.0f));
		return true;
	}

}
