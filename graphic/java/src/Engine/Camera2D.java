package Engine;

public class Camera2D extends ACamera
{
	public Camera2D()
	{
		super();
	}
	
	
	public void	move(Vector2 movement)
	{
		this.position.add(movement);
		this.target.add(movement);
	}
}
