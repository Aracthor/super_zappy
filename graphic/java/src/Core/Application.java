package Core;

import org.lwjgl.input.Keyboard;

import Events.EventsHandler;
import Events.QuitListener;
import Exceptions.ExitException;
import Exceptions.LaunchException;
import Graphics.AView;
import Graphics.ReliefView;
import Graphics.StrategicView;
import Network.NetworkThread;

public class Application implements IApplication
{
	private	Window			window;
	private	NetworkThread	network;
	private EventsHandler	eventsHandler;
	private	AView[]			graphics;
	
	private	int				selectedView;
	private boolean			running;
	
	public Application(String host, String port) throws LaunchException
	{
		network = new NetworkThread(host, port);
		window = new Window();
		window.open();
		graphics = new AView[AView.VIEWS_NUMBER];
		graphics[0] = new StrategicView();
		graphics[1] = new ReliefView();

		selectedView = 0;
		graphics[selectedView].select();
		
		this.prepareEventsHandler();
	}
	
	private void	prepareEventsHandler()
	{
		eventsHandler = new EventsHandler();
		
		eventsHandler.setCloseEvent(new QuitListener());
		
		eventsHandler.addKeyboardEvent(Keyboard.KEY_ESCAPE, new QuitListener());
	}


	public void		run()
	{
		network.start();
		running = true;
		while (running)
		{
			this.handleEvents();
			this.display();
		}
	}
	
	private	void	handleEvents()
	{
		running = eventsHandler.listen();
		if (running)
		{
			graphics[selectedView].handleEvents();
		}
	}
	
	private void	display()
	{
		graphics[selectedView].display();
		window.display();
	}
	
	
	public void		exit() throws ExitException
	{
		try
		{
			network.interrupt();
			network.join();
		}
		catch (InterruptedException exception)
		{
			throw new ExitException("Problem Interrupting network : " + exception.getMessage());
		}
	}
}
