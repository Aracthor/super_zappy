package Graphics;

import org.lwjgl.input.Keyboard;
import org.lwjgl.util.vector.Vector3f;

import Data.Chunk;
import Data.DataManager;
import Data.Hoopla;
import Data.Map;
import Engine.Camera2D;
import Engine.GlControlPanel;
import Engine.Mesh;
import Events.Camera2DMoveDownListener;
import Events.Camera2DMoveLeftListener;
import Events.Camera2DMoveRightListener;
import Events.Camera2DMoveUpListener;
import Events.Camera2DZoomBackListener;
import Events.Camera2DZoomFrontListener;
import Events.EventsHandler;

public class StrategicView extends AView
{
	private Camera2D	camera;
	private	Mesh		map;
	
	public	StrategicView()
	{
		super();
		camera = new Camera2D(60.0f, 800.0f / 600.0f, 0.1f, 1000.0f);
		camera.setPosition(new Vector3f(0.0f, 0.0f, -50.0f));
		camera.setTarget(new Vector3f(0.0f, 0.0f, 0.0f));
		map = new Mesh();
		this.prepareEventsHandler();
	}
	
	public	void	select()
	{
		GlControlPanel.getInstance().setDepthMask(false);
	}
	
	private void	addChunkToVertices(float[] vertices, float[] colors, Chunk chunk, int index, int chunkX, int chunkY)
	{
		Hoopla		hoopla;
		Vector3f	color;
		int			x, y;
		int			i;
		
		chunkX *= Chunk.SIZE;
		chunkY *= Chunk.SIZE;
		
		for (x = 0; x < Chunk.SIZE; ++x)
		{
			for (y = 0; y < Chunk.SIZE; ++y)
			{
				hoopla = chunk.getHoopla(x, y);
				color = hoopla.getGroundType().getColor();
				
				vertices[index +  0] = chunkX + x + 0;	vertices[index +  1] = chunkY + y + 0;	vertices[index +  2] = 0;
				vertices[index +  3] = chunkX + x + 1;	vertices[index +  4] = chunkY + y + 0;	vertices[index +  5] = 0;
				vertices[index +  6] = chunkX + x + 0;	vertices[index +  7] = chunkY + y + 1;	vertices[index +  8] = 0;

				vertices[index +  9] = chunkX + x + 1;	vertices[index + 10] = chunkY + y + 1;	vertices[index + 11] = 0;
				vertices[index + 12] = chunkX + x + 1;	vertices[index + 13] = chunkY + y + 0;	vertices[index + 14] = 0;
				vertices[index + 15] = chunkX + x + 0;	vertices[index + 16] = chunkY + y + 1;	vertices[index + 17] = 0;

				for (i = 0; i < 18; i += 3)
				{
					colors[index +  i + 0] = color.x;	colors[index + i + 1] = color.y;	colors[index + i + 2] = color.z;
				}
				
				index += 18;
			}
		}
	}
	
	private void	prepareMapMesh(Map mapData)
	{
		float		vertices[];
		float		colors[];
		int			x, y;
		int			index;
		
		vertices = new float[mapData.getChunksNumber() * Chunk.SIZE * Chunk.SIZE * 6 * 3];
		colors = new float[mapData.getChunksNumber() * Chunk.SIZE * Chunk.SIZE * 6 * 3];
		for (y = 0; y < mapData.getLarger(); ++y)
		{
			for (x = 0; x < mapData.getLonger(); ++x)
			{
				index = ((y * mapData.getLonger() + x) * Chunk.SIZE * Chunk.SIZE) * 6 * 3;
				this.addChunkToVertices(vertices, colors, mapData.getChunk(x, y), index, x, y);
			}
		}
		
		map.addVertices(vertices);
		map.addColors(colors);
		map.build();
		map.translate(new Vector3f(-mapData.getLonger() / 2 * Chunk.SIZE, -mapData.getLarger() / 2 * Chunk.SIZE, 0));
	}
	
	public	void	manageData(long elapsedTime)
	{
		Map			mapData = DataManager.getInstance().getMap();
		
		if (mapData != null && mapData.isReady() && map.isEmpty())
		{
			this.prepareMapMesh(mapData);
		}
	}
	
	public	void	display(long elapsedTime)
	{
		GlControlPanel.getInstance().initFrame(camera);
		{
			if (map.isEmpty() == false)
			{
				map.draw();
			}
		}
		GlControlPanel.getInstance().endFrame();
	}

	private void prepareEventsHandler()
	{
		eventsHandler = new EventsHandler();
		eventsHandler.addKeyboardEvent(Keyboard.KEY_UP,		new Camera2DMoveUpListener(camera));
		eventsHandler.addKeyboardEvent(Keyboard.KEY_DOWN,	new Camera2DMoveDownListener(camera));
		eventsHandler.addKeyboardEvent(Keyboard.KEY_RIGHT,	new Camera2DMoveRightListener(camera));
		eventsHandler.addKeyboardEvent(Keyboard.KEY_LEFT,	new Camera2DMoveLeftListener(camera));
		eventsHandler.addKeyboardEvent(Keyboard.KEY_Z,		new Camera2DZoomFrontListener(camera));
		eventsHandler.addKeyboardEvent(Keyboard.KEY_S,		new Camera2DZoomBackListener(camera));
	}
}
