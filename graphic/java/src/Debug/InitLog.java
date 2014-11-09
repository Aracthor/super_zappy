package Debug;

public class InitLog implements ILog
{
	private	boolean	active;
	
	public	InitLog()
	{
		active = true;
	}

	@Override
	public void print(String message)
	{
		if (active)
		{
			System.out.println(message);
		}
	}

}
