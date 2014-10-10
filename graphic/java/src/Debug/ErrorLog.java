package Debug;

public class ErrorLog implements ILog
{
	@Override
	public void print(String message)
	{
		System.err.println("Error : " + message);
	}
}
