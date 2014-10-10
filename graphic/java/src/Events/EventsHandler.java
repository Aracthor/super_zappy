package Events;

import java.util.HashMap;
import java.util.Map;

import org.lwjgl.input.Keyboard;
import org.lwjgl.opengl.Display;

public class EventsHandler
{
	private	IListener					closeEvent;
	private	HashMap<Integer, IListener>	keyboardListeners;
	
	public	EventsHandler()
	{
		closeEvent = null;
		keyboardListeners = new HashMap<Integer, IListener>();
	}
	
	
	public void		setCloseEvent(IListener event)
	{
		closeEvent = event;
	}
	
	public void		addKeyboardEvent(int key, IListener event)
	{
		keyboardListeners.put(key, event);
	}
	
	
	public boolean	listen()
	{
		boolean	running = true;
		
		// Close event
		if (closeEvent != null && Display.isCloseRequested())
		{
			running = closeEvent.hear();
		}
		
		// Keyboard Event
		for (Map.Entry<Integer, IListener> listener : keyboardListeners.entrySet())
		{
			if (running == true && Keyboard.isKeyDown(listener.getKey()))
			{
				running = listener.getValue().hear();
			}
		}
		
		return (running);
	}
}
