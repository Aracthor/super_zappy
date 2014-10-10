package Main;

import Core.Application;
import Core.IApplication;

public class GraphicClient
{
	public static void	main(String[] args)
	{
		IApplication	app;
		
		try
		{
			app = new Application(args[1], args[2]);
			app.run();
			app.exit();
		}
		catch (RuntimeException exception)
		{
			System.err.println("Fatal error : " + exception.toString());
		}
	}
}
