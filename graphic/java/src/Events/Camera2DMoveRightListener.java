package Events;

import Engine.Camera2D;
import Engine.Vector2;

public class Camera2DMoveRightListener extends ACamera2DListener
{
	public	Camera2DMoveRightListener(Camera2D camera)
	{
		super(camera);
	}
	
	@Override
	public boolean hear()
	{
		this.camera.move(new Vector2(1.0f, 0.0f));
		return true;
	}

}
