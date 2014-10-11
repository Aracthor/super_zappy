package Graphics;

import org.lwjgl.input.Keyboard;
import org.lwjgl.util.vector.Vector3f;

import Engine.Camera2D;
import Engine.GlControlPanel;
import Engine.Mesh;
import Events.EventsHandler;
import Events.MapMoveDownListener;
import Events.MapMoveLeftListener;
import Events.MapMoveRightListener;
import Events.MapMoveUpListener;

public class StrategicView extends AView
{
	private Camera2D	camera;
	private	Mesh		map;
	
	public	StrategicView()
	{
		super();
		camera = new Camera2D(60.0f, 800.0f / 600.0f, 0.1f, 100.0f);
		camera.setPosition(new Vector3f(0.0f, 0.0f, -1.0f));
		camera.setTarget(new Vector3f(0.0f, 0.0f, 0.0f));
		map = new Mesh();
		this.prepareEventsHandler();
		
		/* TEST */
		float	vertices[] = {
			
			// Left bottom triangle
			-0.5f, 0.5f, 0.0f,
			-0.5f, -0.5f, 0.0f,
			0.5f, -0.5f, 0.0f,
			// Right top triangle
			0.5f, -0.5f, 0.0f,
			0.5f, 0.5f, 0.0f,
			-0.5f, 0.5f, 0.0f
		};
		map.addVertices(vertices);
	}
	
	public	void	select()
	{
		GlControlPanel.getInstance().setDepthMask(false);
	}
	
	public	void	display(long elapsedTime)
	{
		GlControlPanel.getInstance().initFrame(camera);
		map.draw();
		GlControlPanel.getInstance().endFrame();
	}

	private void prepareEventsHandler()
	{
		eventsHandler = new EventsHandler();
		eventsHandler.addKeyboardEvent(Keyboard.KEY_UP,		new MapMoveUpListener(map));
		eventsHandler.addKeyboardEvent(Keyboard.KEY_DOWN,	new MapMoveDownListener(map));
		eventsHandler.addKeyboardEvent(Keyboard.KEY_RIGHT,	new MapMoveRightListener(map));
		eventsHandler.addKeyboardEvent(Keyboard.KEY_LEFT,	new MapMoveLeftListener(map));
	}
}
