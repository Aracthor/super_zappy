package Graphics;

import Data.DataManager;
import Data.Map;
import Engine.GlControlPanel;
import Events.EventsHandler;


public class ReliefView extends AView
{
	public	ReliefView()
	{
		this.prepareEventsHandler();
	}
	
	public	void	select()
	{
		GlControlPanel.getInstance().setDepthMask(true);
	}
	
	public	void	manageData(long elapsedTime)
	{
	}
	
	public	void	display(long elapsedTime)
	{
		DataManager	dataManager = DataManager.getInstance();
		Map			map;
		
		map = dataManager.getMap();
		if (map.isReady())
		{
			System.out.println("YOLO");
		}
	}

	private void prepareEventsHandler()
	{
		eventsHandler = new EventsHandler();
	}
}
