package Graphics;

import org.lwjgl.input.Keyboard;
import org.lwjgl.util.vector.Vector3f;

import Data.Chunk;
import Data.DataManager;
import Data.Hoopla;
import Data.Map;
import Engine.GlControlPanel;
import Engine.HelicopterCamera;
import Engine.Mesh;
import Events.EventsHandler;
import Events.HelicopterCameraMoveBackListener;
import Events.HelicopterCameraMoveFrontListener;
import Events.HelicopterCameraRotateLeftListener;
import Events.HelicopterCameraRotateRightListener;


public class ReliefView extends AView
{
	private HelicopterCamera	camera;
	private	Mesh				map;
	
	public	ReliefView()
	{
		super();
		camera = new HelicopterCamera();
		camera.setPosition(0.0f, 0.0f, 20.0f);
		map = new Mesh();
		this.prepareEventsHandler();
	}
	
	public	void	select()
	{
		GlControlPanel.getInstance().setDepthMask(true);
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
				
				vertices[index +  0] = chunkX + x + 0;	vertices[index +  1] = chunkY + y + 0;	vertices[index +  2] = hoopla.getHeight() / 10.0f;
				vertices[index +  3] = chunkX + x + 1;	vertices[index +  4] = chunkY + y + 0;	vertices[index +  5] = hoopla.getHeight() / 10.0f;
				vertices[index +  6] = chunkX + x + 0;	vertices[index +  7] = chunkY + y + 1;	vertices[index +  8] = hoopla.getHeight() / 10.0f;

				vertices[index +  9] = chunkX + x + 1;	vertices[index + 10] = chunkY + y + 1;	vertices[index + 11] = hoopla.getHeight() / 10.0f;
				vertices[index + 12] = chunkX + x + 1;	vertices[index + 13] = chunkY + y + 0;	vertices[index + 14] = hoopla.getHeight() / 10.0f;
				vertices[index + 15] = chunkX + x + 0;	vertices[index + 16] = chunkY + y + 1;	vertices[index + 17] = hoopla.getHeight() / 10.0f;

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
		eventsHandler.addKeyboardEvent(Keyboard.KEY_UP,		new HelicopterCameraMoveFrontListener(camera));
		eventsHandler.addKeyboardEvent(Keyboard.KEY_DOWN,	new HelicopterCameraMoveBackListener(camera));
		eventsHandler.addKeyboardEvent(Keyboard.KEY_RIGHT,	new HelicopterCameraRotateRightListener(camera));
		eventsHandler.addKeyboardEvent(Keyboard.KEY_LEFT,	new HelicopterCameraRotateLeftListener(camera));
	}
}
