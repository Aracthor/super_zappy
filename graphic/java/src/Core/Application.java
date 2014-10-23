package Core;

import org.lwjgl.input.Keyboard;

import Data.DataManager;
import Data.Map;
import Engine.Clock;
import Engine.GlControlPanel;
import Engine.GlException;
import Engine.ShaderControlPanel;
import Events.EventsHandler;
import Events.IncrementListener;
import Events.IncrementableEnum;
import Events.QuitListener;
import Exceptions.ExitException;
import Exceptions.LaunchException;
import Graphics.AView;
import Graphics.ReliefView;
import Graphics.StrategicView;
import Network.NetworkThread;

public class Application implements IApplication
{
	private Clock			clock;
	private	Window			window;
	private	NetworkThread	network;
	private EventsHandler	eventsHandler;
	private	AView[]			graphics;
	
	private	IncrementableEnum	selectedView;
	private int					lastView;
	private boolean				running;
	private boolean				waitingForChunks;
	
	public Application(String host, String port) throws LaunchException
	{
		clock = new Clock();
		network = new NetworkThread(host, port);
		window = new Window();
		window.open();
		this.compileShaders();
		this.initGraphicsModes();
		this.prepareEventsHandler();
		waitingForChunks = false;
	}
	
	private void			compileShaders()
	{
		ShaderControlPanel	shaderControlPanel;
		
		try
		{
			shaderControlPanel = GlControlPanel.getInstance();
			shaderControlPanel.addShader("basic", "ressources/shaders/basic");
			shaderControlPanel.selectShader("basic");
		}
		catch (GlException exception)
		{
			throw new LaunchException("GL error : " + exception.getMessage());
		}
	}
	
	private void	initGraphicsModes()
	{
		graphics = new AView[AView.VIEWS_NUMBER];
		graphics[0] = new StrategicView();
		graphics[1] = new ReliefView();

		selectedView = new IncrementableEnum(graphics.length);
		graphics[selectedView.getId()].select();

	}
	
	private void	prepareEventsHandler()
	{
		eventsHandler = new EventsHandler();
		
		eventsHandler.setCloseEvent(new QuitListener());
		
		eventsHandler.addKeyboardEvent(Keyboard.KEY_ESCAPE, new QuitListener());
		eventsHandler.addKeyboardEvent(Keyboard.KEY_F4, new IncrementListener(selectedView));
	}


	public void		run()
	{
		network.start();
		running = true;
		while (running)
		{
			this.manageData();
			this.handleEvents();
			this.display();
			if (running)
			{
				running = network.isRunning();
			}
		}
	}
	
	private void	manageData()
	{
		Map			map;
		
		map = DataManager.getInstance().getMap();
		
		if (waitingForChunks == false)
		{
			if (map != null && map.isReady() == false)
			{
				network.askForChunks();
				waitingForChunks = true;
			}
		}
		else if (map.isReady())
		{
			waitingForChunks = false;
		}
		
		clock.update();
		if (lastView != selectedView.getId())
		{
			graphics[selectedView.getId()].select();
		}
		graphics[selectedView.getId()].manageData(clock.getElapsedTime());
		lastView = selectedView.getId();
	}
	
	private	void	handleEvents()
	{
		running = eventsHandler.listen();
		if (running)
		{
			graphics[selectedView.getId()].handleEvents(clock.getElapsedTime());
		}
	}
	
	private void	display()
	{
		graphics[selectedView.getId()].display(clock.getElapsedTime());
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
