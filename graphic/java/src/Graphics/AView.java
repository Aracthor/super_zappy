package Graphics;

import Events.EventsHandler;

public abstract class AView
{
	public static int	VIEWS_NUMBER = 2;
	
	
	protected	EventsHandler	eventsHandler;
	
	public	AView()
	{
	}
	
	
	public void	handleEvents()
	{
		eventsHandler.listen();
	}
	
	public	abstract void	select();
	public	abstract void	display();
}
