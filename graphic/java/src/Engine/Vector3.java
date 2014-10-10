package Engine;

public class Vector3
{
	public	float	x;
	public	float	y;
	public	float	z;
	
	public	Vector3()
	{
		this.x = 0;
		this.y = 0;
		this.z = 0;
	}
	
	public	Vector3(float x, float y, float z)
	{
		this.x = x;
		this.y = y;
		this.z = z;
	}
	
	public	Vector3(Vector3 ref)
	{
		this.x = ref.x;
		this.y = ref.y;
		this.z = ref.z;
	}

	
	public void	add(float ref)
	{
		this.x += ref;
		this.y += ref;
		this.z += ref;
	}
	
	public void	add(Vector2 ref)
	{
		this.x += ref.x;
		this.y += ref.y;
	}
	
	public void	add(Vector3 ref)
	{
		this.x += ref.x;
		this.y += ref.y;
		this.z += ref.z;
	}
	
	public void	sub(float ref)
	{
		this.x -= ref;
		this.y -= ref;
		this.z -= ref;
	}
	
	public void	sub(Vector3 ref)
	{
		this.x -= ref.x;
		this.y -= ref.y;
		this.z -= ref.z;
	}
	
	public void	mult(float ref)
	{
		this.x *= ref;
		this.y *= ref;
		this.z *= ref;
	}
	
	public void	div(float ref)
	{
		this.x /= ref;
		this.y /= ref;
		this.z /= ref;
	}
}
