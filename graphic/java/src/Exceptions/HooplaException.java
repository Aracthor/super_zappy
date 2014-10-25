package Exceptions;

import Data.Hoopla;

public class HooplaException extends RuntimeException
{
	private static final long		serialVersionUID = 104;

	public static HooplaException	create(Hoopla hoopla)
	{
		String	message;
		
		if (hoopla.getGroundType() == null)
		{
			message = "Invalid ground";
		}
		else if (hoopla.getItemType() == null)
		{
			message = "Invalid item";
		}
		else if (hoopla.getObjectType() == null)
		{
			message = "Invalid object";
		}
		else
		{
			message = "Invalid error";
		}
		
		return (new HooplaException(message + " for a hoopla."));
	}
	
	public	HooplaException(String message)
	{
		super(message);
	}
}
