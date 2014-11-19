package Core;

import org.lwjgl.input.Keyboard;

import Data.DataManager;
import Data.Map;
import Engine.Clock;
import Engine.GlControlPanel;
import Engine.ShaderControlPanel;
import Events.EventsHandler;
import Events.IncrementListener;
import Events.IncrementableEnum;
import Events.QuitListener;
import Exceptions.ExitException;
import Exceptions.GlException;
import Exceptions.LaunchException;
import Graphics.AView;
import Graphics.GraphicWarehouse;
import Graphics.Relief.ReliefView;
import Graphics.Strategic.StrategicView;
import Network.NetworkThread;

public class Application implements IApplication
{
	private static long		s_totalElapsedTime = 0;
	
	public static long		getTotalElapsedTime()
	{
		return (s_totalElapsedTime);
	}
	
	
	private Clock			clock;
	private	Window			window;
	private	NetworkThread	network;
	private EventsHandler	eventsHandler;
	private	AView[]			graphics;
	
	private	IncrementableEnum	selectedView;
	private int					lastView;
	private boolean				running;
	private boolean				mapReceived;
	
	public Application(String host, String port) throws LaunchException
	{
		clock = new Clock();
		network = new NetworkThread(host, port);
		window = new Window();
		window.open();
		GraphicWarehouse.createWarehouse();
		this.compileShaders();
		this.initGraphicsModes();
		this.prepareEventsHandler();
		mapReceived = false;
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
	
	private void	checkMapStatus()
	{
		Map			map;
		int			i;
		
		map = DataManager.getInstance().getMap();
		
		if (map != null && mapReceived == false)
		{
			for (i = 0; i < AView.VIEWS_NUMBER; ++i)
			{
				graphics[i].initData(map.getLonger(), map.getLarger());
			}
			mapReceived = true;
		}
	}
	
	private void	manageData()
	{
		this.checkMapStatus();
		
		clock.update();
		s_totalElapsedTime += clock.getElapsedTime();
		
		DataManager.getInstance().update(clock.getElapsedTime());
		
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
