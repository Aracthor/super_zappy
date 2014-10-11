package Graphics;

import Events.EventsHandler;

public abstract class AView
{
	public static int	VIEWS_NUMBER = 2;
	
	
	protected	EventsHandler	eventsHandler;
	
	public	AView()
	{
	}
	
	
	public void	handleEvents(long elapsedTime)
	{
		eventsHandler.listen(elapsedTime);
	}
	
	public	abstract void	select();
	public	abstract void	display(long elapsedTime);
}
