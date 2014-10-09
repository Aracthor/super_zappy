package Core;

public class LaunchException extends RuntimeException
{
	private static final long serialVersionUID = 42;

	public LaunchException()
	{
		super();
	}

	public LaunchException(String message)
	{
		super(message);
	}
}
