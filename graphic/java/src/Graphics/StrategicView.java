package Graphics;

import org.lwjgl.input.Keyboard;

import Engine.Camera2D;
import Events.Camera2DMoveDownListener;
import Events.Camera2DMoveLeftListener;
import Events.Camera2DMoveRightListener;
import Events.Camera2DMoveUpListener;
import Events.EventsHandler;

public class StrategicView extends AView
{
	private Camera2D			camera;
	private	VertexArrayObject	map;
	
	public	StrategicView()
	{
		super();
		camera = new Camera2D();
		map = new VertexArrayObject();
		this.prepareEventsHandler();
		
		/* TEST */
		float	vertices[] = {
			// Left bottom triangle
			-0.5f, 0.5f, 0f,
			-0.5f, -0.5f, 0f,
			0.5f, -0.5f, 0f,
			// Right top triangle
			0.5f, -0.5f, 0f,
			0.5f, 0.5f, 0f,
			-0.5f, 0.5f, 0f
		};
		map.addMesh(vertices);
	}
	
	public	void	select()
	{
		GlControlPanel.getInstance().setDepthMask(false);
	}
	
	public	void	display()
	{
		map.draw();
	}

	private void prepareEventsHandler()
	{
		eventsHandler = new EventsHandler();
		eventsHandler.addKeyboardEvent(Keyboard.KEY_UP,		new Camera2DMoveUpListener(camera));
		eventsHandler.addKeyboardEvent(Keyboard.KEY_DOWN,	new Camera2DMoveDownListener(camera));
		eventsHandler.addKeyboardEvent(Keyboard.KEY_RIGHT,	new Camera2DMoveRightListener(camera));
		eventsHandler.addKeyboardEvent(Keyboard.KEY_LEFT,	new Camera2DMoveLeftListener(camera));
	}
}
