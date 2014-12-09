package Graphics.Strategic;

import org.lwjgl.input.Keyboard;
import org.lwjgl.util.vector.Vector3f;

import Data.Chunk;
import Data.Player;
import Engine.GlControlPanel;
import Engine.Camera.Camera2D;
import Events.EventsHandler;
import Events.Camera2D.Camera2DMoveDownListener;
import Events.Camera2D.Camera2DMoveLeftListener;
import Events.Camera2D.Camera2DMoveRightListener;
import Events.Camera2D.Camera2DMoveUpListener;
import Events.Camera2D.Camera2DZoomBackListener;
import Events.Camera2D.Camera2DZoomFrontListener;
import Graphics.AGraphicChunk;
import Graphics.AGraphicPlayer;
import Graphics.AView;

public class StrategicView extends AView
{
	public	StrategicView()
	{
		super();
		camera = new Camera2D();
		camera.setPosition(new Vector3f(50.0f, 0.0f, 0.0f));
		this.prepareEventsHandler();
	}
	
	@Override
	public void	initData(int longer, int larger)
	{
		super.initData(longer, larger);
		
		camera.setPosition(8.0f * (longer + larger), larger * Chunk.SIZE / 2.0f, longer * Chunk.SIZE / 2.0f);
		camera.setTarget(0.0f, larger * Chunk.SIZE / 2.0f, longer * Chunk.SIZE / 2.0f);
	}
	
	public	void	select()
	{
		super.select();
		GlControlPanel.getInstance().setDepthMask(false);
		GlControlPanel.getInstance().setTexture2D(true);
	}
	
	@Override
	protected AGraphicChunk	createGraphicChunk(int x, int y, Chunk chunk)
	{
		return (new StrategicGraphicChunk(x, y, chunk));
	}
	
	@Override
	protected AGraphicPlayer	createGraphicPlayer(Player player)
	{
		return (new StrategicGraphicPlayer(player));
	}
	
	@Override
	public	void	manageData(long elapsedTime)
	{
		super.manageData(elapsedTime);
	}
	
	@Override
	public	void	displayChunks(long elapsedTime)
	{
		if (((Camera2D)camera).getZoom() > 100.0f)
		{
			this.displayAllChunks(elapsedTime);
		}
		else
		{
			this.displaySomeChunks(elapsedTime, new StrategicChunkSorter(camera.getPosition().z, camera.getPosition().y));
		}
	}

	private void prepareEventsHandler()
	{
		eventsHandler = new EventsHandler();
		eventsHandler.addKeyboardEvent(Keyboard.KEY_UP,		new Camera2DMoveUpListener(camera));
		eventsHandler.addKeyboardEvent(Keyboard.KEY_DOWN,	new Camera2DMoveDownListener(camera));
		eventsHandler.addKeyboardEvent(Keyboard.KEY_RIGHT,	new Camera2DMoveRightListener(camera));
		eventsHandler.addKeyboardEvent(Keyboard.KEY_LEFT,	new Camera2DMoveLeftListener(camera));
		eventsHandler.addKeyboardEvent(Keyboard.KEY_W,		new Camera2DZoomFrontListener(camera));
		eventsHandler.addKeyboardEvent(Keyboard.KEY_S,		new Camera2DZoomBackListener(camera));
	}
}
