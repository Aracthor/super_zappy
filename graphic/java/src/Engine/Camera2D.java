package Engine;


public class Camera2D extends ACamera
{
	private float	speed = 0.01f;
	
	public Camera2D()
	{
		super();
	}

	public Camera2D(float angle, float aspectRatio, float znear, float zfar)
	{
		super(angle, aspectRatio, znear, zfar);
	}

	
	public void	move(float x, float y)
	{
		x *= speed;
		y *= speed;
		
		this.position.x += x;
		this.position.y += y;
		this.target.x += x;
		this.target.y += y;
	}
}
