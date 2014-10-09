package Core;

import Engine.IApplication;

public class Application implements IApplication
{
	private	Window	window;
	boolean			running;
	
	public Application(String host, String port) throws LaunchException
	{
		this.window = new Window();
		this.window.open();
		this.running = true;
	}
	
	
	public void		run()
	{
		while (this.running)
		{
			this.display();
		}
	}
	
	private void	display()
	{
		window.display();
	}
}
