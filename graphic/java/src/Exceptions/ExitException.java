package Exceptions;

public class ExitException extends RuntimeException
{
	private static final long serialVersionUID = 102; // useless

	public ExitException()
	{
		super();
	}

	public ExitException(String message)
	{
		super(message);
	}
}
