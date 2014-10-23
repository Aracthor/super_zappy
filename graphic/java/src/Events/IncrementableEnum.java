package Events;

public class			IncrementableEnum
{
	private final int	max;
	private int			id;
	
	public IncrementableEnum(int max)
	{
		this.max = max;
		this.id = 0;
	}
	
	public int	getMax()
	{
		return (max);
	}
	
	public int	getId()
	{
		return (id);
	}
	
	public void	increment()
	{
		++id;
		if (id == max)
		{
			id = 0;
		}
	}
	
	public void	decrement()
	{
		if (id == 0)
		{
			id = max;
		}
		--id;
	}
}
