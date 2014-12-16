package Data;

import Debug.DebugLog;

public class		Hurtable
{
	protected int	life;
	
	public		Hurtable()
	{
		this.life = 0;
	}
	
	public		Hurtable(int life)
	{
		this.life = life;
	}
	
	public void	setLife(int life)
	{
		DebugLog.getInstance().events.print("A player change life : " + life);
		this.life = life;
	}
	
	
	public int	getLife()
	{
		return (life);
	}
}
