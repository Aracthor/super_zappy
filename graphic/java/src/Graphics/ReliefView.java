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
		float		height;
		int			x, y;
		
		chunkX *= Chunk.SIZE;
		chunkY *= Chunk.SIZE;
		
		for (x = 0; x < Chunk.SIZE; ++x)
		{
			for (y = 0; y < Chunk.SIZE; ++y)
			{
				hoopla = chunk.getHoopla(x, y);
				color = hoopla.getGroundType().getColor();
				height = hoopla.getHeight() / 10.0f;
				if (height < 0.0f)
				{
					height = 0.0f;
				}
				
				vertices[index +  0] = chunkX + x;
				vertices[index +  1] = chunkY + y;
				vertices[index +  2] = height;

				colors[index + 0] = color.x;
				colors[index + 1] = color.y;
				colors[index + 2] = color.z;
				
				index += 3;
			}
		}
	}
	
	
	private void	addChunkToIndices(int[] indices, Chunk chunk, int index, int chunkx, int chunky, int longer, int larger)
	{
		int			x, y;
		
		for (x = 0; x < Chunk.SIZE; ++x)
		{
			for (y = 0; y < Chunk.SIZE; ++y)
			{
				if ((chunkx != longer - 1 || x != Chunk.SIZE - 1) && (y != Chunk.SIZE - 1))
				{
					indices[index + 0] = 0 + index / 6;
					indices[index + 1] = 1 + index / 6;
					indices[index + 2] = Chunk.SIZE + index / 6;
					indices[index + 3] = Chunk.SIZE + 1 + index / 6;
					indices[index + 4] = 1 + index / 6;
					indices[index + 5] = Chunk.SIZE + index / 6;
				}
				else if (chunkx != longer - 1 || x != Chunk.SIZE - 1)
				{
					/*
					int toAdd = -Chunk.SIZE * Chunk.SIZE * larger - Chunk.SIZE;
					indices[index + 0] = 0 + index / 6;
					indices[index + 1] = 1 + index / 6;
					indices[index + 2] = 0 + index / 6 + toAdd;
					indices[index + 3] = 1 + index / 6 + toAdd;
					indices[index + 4] = 1 + index / 6;
					indices[index + 5] = 0 + index / 6 + toAdd;
					*/					
				}
				
				index += 6;
			}
		}
	}
		
	private void	prepareMapMesh(Map mapData)
	{
		float		vertices[];
		float		colors[];
		int			indices[];
		int			x, y;
		int			verticesIndex;
		int			indicesIndex;
		
		vertices = new float[mapData.getChunksNumber() * Chunk.SIZE * Chunk.SIZE * 3];
		colors = new float[mapData.getChunksNumber() * Chunk.SIZE * Chunk.SIZE * 3];
		indices = new int[mapData.getChunksNumber() * Chunk.SIZE * Chunk.SIZE * 6];
		for (y = 0; y < mapData.getLarger(); ++y)
		{
			for (x = 0; x < mapData.getLonger(); ++x)
			{
				verticesIndex = ((y * mapData.getLonger() + x) * Chunk.SIZE * Chunk.SIZE) * 3;
				indicesIndex = ((y * mapData.getLonger() + x) * Chunk.SIZE * Chunk.SIZE) * 6;
				this.addChunkToVertices(vertices, colors, mapData.getChunk(x, y), verticesIndex, x, y);
				this.addChunkToIndices(indices, mapData.getChunk(x, y), indicesIndex, x, y, mapData.getLonger(), mapData.getLarger());
			}
		}
		
		map.addVertices(vertices);
		map.addColors(colors);
		map.addElements(indices);
		map.build();
	}
		
	public	void	manageData(long elapsedTime)
	{
		Map			mapData = DataManager.getInstance().getMap();
		
		if (mapData != null && mapData.isReady() && map.isEmpty())
		{
			this.prepareMapMesh(mapData);
			camera.setPosition(mapData.getLonger() / 2 * Chunk.SIZE, mapData.getLarger() / 2 * Chunk.SIZE);
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
