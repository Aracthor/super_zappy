package Engine;

public class Clock
{
	private	long	lastTime;
	private long	elapsedTime;
	private long	totalElapsedTime;
	
	public	Clock()
	{
		this.reset();
	}
	
	public	long	getElapsedTime()
	{
		return (elapsedTime);
	}
	
	public	long	getTotalElapsedTime()
	{
		return (totalElapsedTime);
	}
	
	public void		update()
	{
		long		newTime;
		
		newTime = System.currentTimeMillis();
		elapsedTime = newTime - lastTime;
		totalElapsedTime += elapsedTime;
		lastTime = newTime;
	}
	
	public void		reset()
	{
		lastTime = System.currentTimeMillis();
		elapsedTime = 0;
		totalElapsedTime = 0;
	}
}
