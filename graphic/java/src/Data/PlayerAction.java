package Data;

public class PlayerAction
{
	private final EAction	action;
	private final long		totalTime;
	private long			remainingTime;
	private int				param;
	private int				x;
	private int				y;
	
	public	PlayerAction(EAction action, long time)
	{
		this(action, time, 0);
	}
	
	public	PlayerAction(EAction action, long time, int param)
	{
		time *= DataManager.getInstance().getSpeed();
		this.action = action;
		this.totalTime = time;
		this.remainingTime = time;
		this.param = param;
		this.x = 0;
		this.y = 0;
	}
	
	public void	setParam(int param)
	{
		this.param = param;
	}
	
	public void	setCoords(int x, int y)
	{
		this.x = x;
		this.y = y;
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
	
	public int	getParam()
	{
		return (param);
	}
	
	public int	getX()
	{
		return (x);
	}
	
	public int	getY()
	{
		return (y);
	}
	
	public	float	getPercentage()
	{
		return (100.0f - 100.0f * (float)((double)remainingTime / (double)totalTime));
	}
}
