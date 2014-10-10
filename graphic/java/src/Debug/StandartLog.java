package Debug;

public class StandartLog implements ILog
{
	@Override
	public void print(String message)
	{
		if (message.charAt(message.length() - 1) == '\n')
		{
			message.substring(0, message.length() - 1);
		}
		System.out.println(message);
	}
}
