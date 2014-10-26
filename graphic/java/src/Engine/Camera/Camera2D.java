package Engine.Camera;


public class Camera2D extends ACamera
{
	private float	speed = 0.001f;
	
	public Camera2D()
	{
		super(60.0f, 800.0f / 600.0f, 0.1f, 10000.0f);
	}

	public Camera2D(float angle, float aspectRatio, float znear, float zfar)
	{
		super(angle, aspectRatio, znear, zfar);
	}

	
	public void	move(float x, float y)
	{
		x *= speed * -this.position.x;
		y *= speed * -this.position.x;
		
		this.position.y += x;
		this.position.z += y;
		this.target.y += x;
		this.target.z += y;
	}
	
	public void	zoom(float zoom)
	{
		this.position.x *= zoom;
	}
}
