package Main;

import Engine.IApplication;
import Core.Application;

public class GraphicClient
{
	public static void	main(String[] args)
	{
		IApplication	app;
		
		try
		{
			app = new Application(args[0], args[1]);
			app.run();
		}
		catch (RuntimeException exception)
		{
			System.err.println("Fatal error : " + exception.toString());
		}
	}
}
