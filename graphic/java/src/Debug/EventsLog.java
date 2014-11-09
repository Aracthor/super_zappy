package Debug;

public class EventsLog implements ILog
{
	private	boolean	active;
	
	public	EventsLog()
	{
		active = true;
	}
	
	@Override
	public void print(String message)
	{
		if (active)
		{
			if (message.charAt(message.length() - 1) == '\n')
			{
				message.substring(0, message.length() - 1);
			}
			System.out.println(message);
		}
	}
}
