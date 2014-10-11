package Graphics;

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
	
	public	void	display(long elapsedTime)
	{
	}

	private void prepareEventsHandler()
	{
		eventsHandler = new EventsHandler();
	}
}
