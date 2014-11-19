package Data;

public class PlayerAction
{
	private final EAction	action;
	private final long		totalTime;
	private long			remainingTime;
	
	public	PlayerAction(EAction action)
	{
		this.action = action;
		this.totalTime = 42;
		this.remainingTime = 42;
	}
	
	public	PlayerAction(EAction action, long time)
	{
		time *= DataManager.getInstance().getSpeed();
		this.action = action;
		this.totalTime = time;
		this.remainingTime = time;
	}
	
	public	EAction	getId()
	{
		return (action);
	}
	
	public void	retireTime(long elapsedTime)
	{
		remainingTime -= elapsedTime * 1000.0f;
	}
	
	public long	getRemainingTime()
	{
		return (remainingTime);
	}
	
	public	float	getPercentage()
	{
		return (100.0f - 100.0f * (float)((double)remainingTime / (double)totalTime));
	}
}
