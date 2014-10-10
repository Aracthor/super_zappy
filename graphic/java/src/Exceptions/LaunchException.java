package Exceptions;

public class LaunchException extends RuntimeException
{
	private static final long serialVersionUID = 101; // useless

	public LaunchException()
	{
		super();
	}

	public LaunchException(String message)
	{
		super(message);
	}
}
