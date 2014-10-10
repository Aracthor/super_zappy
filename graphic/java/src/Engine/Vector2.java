package Engine;

public class Vector2
{
	public	float	x;
	public	float	y;
	
	public	Vector2()
	{
		this.x = 0;
		this.y = 0;
	}
	
	public	Vector2(float x, float y)
	{
		this.x = x;
		this.y = y;
	}
	
	public	Vector2(Vector2 ref)
	{
		this.x = ref.x;
		this.y = ref.y;
	}

	
	public void	add(float ref)
	{
		this.x += ref;
		this.y += ref;
	}
	
	public void	add(Vector2 ref)
	{
		this.x += ref.x;
		this.y += ref.y;
	}
	
	public void	sub(float ref)
	{
		this.x -= ref;
		this.y -= ref;
	}
	
	public void	sub(Vector2 ref)
	{
		this.x -= ref.x;
		this.y -= ref.y;
	}
	
	public void	mult(float ref)
	{
		this.x *= ref;
		this.y *= ref;
	}
	
	public void	div(float ref)
	{
		this.x /= ref;
		this.y /= ref;
	}
}
