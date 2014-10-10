package Engine;


public abstract class ACamera
{
	protected	Vector3	position;
	protected	Vector3	target;
	
	public	ACamera()
	{
		position = new Vector3(0.0f, 0.0f, 0.0f);
		target = new Vector3(0.0f, 0.0f, 0.0f);
	}
	
	protected	void	setPosition(Vector3 position)
	{
		this.position = position;
	}
	
	protected	void	setTarget(Vector3 target)
	{
		this.target = target;
	}
	
	
	public	Vector3	getPosition()
	{
		return (position);
	}
	
	public	Vector3	getTarget()
	{
		return (target);
	}
}
