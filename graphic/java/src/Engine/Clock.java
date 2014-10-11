package Engine;

public class Clock
{
	private	long	lastTime;
	private long	elapsedTime;
	
	public	Clock()
	{
		this.reset();
	}
	
	public	long	getElapsedTime()
	{
		return (elapsedTime);
	}
	
	public void		update()
	{
		long		newTime;
		
		newTime = System.currentTimeMillis();
		elapsedTime = newTime - lastTime;
		lastTime = newTime;
	}
	
	public void		reset()
	{
		lastTime = System.currentTimeMillis();
		elapsedTime = 0;
	}
}
