package Engine.Camera;

import org.lwjgl.util.vector.Vector3f;

public class HelicopterCamera extends AAngledCamera
{
	private float	sensitivity;
	private float	speed;
	
	public HelicopterCamera()
	{
		super(70.0f, 800.0f / 600.0f, 0.1f, 1000.0f);
		angleX = 0.0f;
		angleY = -45.0f;
		sensitivity = 0.3f;
		speed = 0.05f;
	}
	
	
	private Vector3f	getMovement(float amplitude)
	{
		Vector3f		movement = new Vector3f(target);
		
		Vector3f.sub(target, position, movement);
		movement.z = 0;
		
		movement.normalise();
		movement.x *= amplitude;
		movement.y *= amplitude;
		
		return (movement);
	}
	
	
	public void	setSensitivity(float sensitivity)
	{
		this.sensitivity = sensitivity;
	}
	
	public void	avance(float amplitude)
	{
		Vector3f	movement = this.getMovement(speed * amplitude);
		
		Vector3f.add(position, movement, position);
		Vector3f.add(target, movement, target);
	}
	
	public void	rotate(float amplitude)
	{
		angleX += amplitude * sensitivity;
		if (angleX < 0.0f)
		{
			angleX += 360.0f;
		}
		else if (angleX > 360.0f)
		{
			angleX -= 360.0f;
		}
	}
	
	
	public float	getAngleX()
	{
		return (angleX);
	}
}
