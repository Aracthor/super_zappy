package Main;

import Core.Application;
import Core.IApplication;
import Exceptions.ConnectionException;

public class GraphicClient
{
	public static void	main(String[] args)
	{
		IApplication	app;
		
		if (args.length != 3)
		{
			System.err.println("USAGE : " + args[0] + " host port");
		}
		else
		{
			try
			{
				app = new Application(args[1], args[2]);
				app.run();
				app.exit();
			}
			catch (ConnectionException exception)
			{
				System.err.println("Cannot connect to this host.");
			}
			catch (RuntimeException exception)
			{
				exception.printStackTrace();
			}
		}
	}
}
