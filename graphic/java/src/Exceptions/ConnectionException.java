package Exceptions;

public class ConnectionException extends LaunchException
{
	private static final long serialVersionUID = 103; // useless
	
	public ConnectionException()
	{
		super("Connection failed");
	}
}
