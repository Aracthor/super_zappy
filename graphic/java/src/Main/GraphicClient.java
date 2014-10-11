package Main;

import Core.Application;
import Core.IApplication;

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
			catch (RuntimeException exception)
			{
				exception.printStackTrace();
			}
		}
	}
}
