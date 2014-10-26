package Graphics.Relief;

import org.lwjgl.input.Keyboard;
import org.lwjgl.util.vector.Vector3f;

import Data.Chunk;
import Data.DataManager;
import Data.Hoopla;
import Data.Map;
import Engine.GlControlPanel;
import Engine.Camera.HelicopterCamera;
import Engine.Models.Mesh;
import Events.BooleanSwitchListener;
import Events.EventsHandler;
import Events.HelicopterCamera.HelicopterCameraMoveBackListener;
import Events.HelicopterCamera.HelicopterCameraMoveFrontListener;
import Events.HelicopterCamera.HelicopterCameraRotateLeftListener;
import Events.HelicopterCamera.HelicopterCameraRotateRightListener;
import Graphics.AGraphicChunk;
import Graphics.AView;
import Usefull.Pointer;


public class ReliefView extends AView
{
	private HelicopterCamera	camera;
	private Mesh				chunksBorders;
	private Pointer<Boolean>	grid;
	
	public	ReliefView()
	{
		super();
		camera = new HelicopterCamera();
		camera.setPosition(0.0f, 0.0f, 20.0f);
		grid = new Pointer<Boolean>(false);
		this.prepareEventsHandler();
	}
	
	@Override
	public void		initData(int longer, int larger)
	{
		super.initData(longer, larger);
		
		camera.setPosition(longer / 2 * Chunk.SIZE, larger / 2 * Chunk.SIZE);
	}
	
	public	void	select()
	{
		super.select();
		GlControlPanel.getInstance().setDepthMask(true);
		GlControlPanel.getInstance().setTexture2D(false);
	}
	
	
	protected AGraphicChunk	createGraphicChunk(int x, int y, Chunk chunk)
	{
		return (new ReliefGraphicChunk(x, y, chunk));
	}
	
	public	void	display(long elapsedTime)
	{
		GlControlPanel.getInstance().initFrame(camera);
		{
			this.displayAllChunks(elapsedTime);
			if (chunksBorders != null)
			{
				chunksBorders.draw();
			}
		}
		GlControlPanel.getInstance().endFrame();
	}
	
	private void	addHooplaToBrodersMeshVertices(float vertices[], float colors[], Hoopla hoopla, int x, int y, int index)
	{
		Vector3f	color;
		float		height;
		
		color = hoopla.getGroundType().getColor();
		height = hoopla.getHeight() / 10.0f;
		if (height < 0.0f)
		{
			height = 0.0f;
		}
		
		vertices[index +  0] = x;
		vertices[index +  1] = y;
		vertices[index +  2] = height;

		colors[index + 0] = color.x;
		colors[index + 1] = color.y;
		colors[index + 2] = color.z;
	}
	
	private void	addChunkToBordersMeshVertices(float vertices[], float colors[], Map map, int chunkX, int chunkY, int index, boolean borderX, boolean borderY)
	{
		int			x, y;
		int			toAddX, toAddY;
		Hoopla		hoopla;
		
		toAddX = chunkX * Chunk.SIZE;
		toAddY = chunkY * Chunk.SIZE;
		
		if (borderY == false)
		{
			for (x = 0; x < Chunk.SIZE; ++x)
			{
				hoopla = map.getChunk(chunkX, chunkY).getHoopla(x, Chunk.SIZE - 1);
				this.addHooplaToBrodersMeshVertices(vertices, colors, hoopla, x + toAddX, Chunk.SIZE - 1 + toAddY, index);
				index += 3;
				
				hoopla = map.getChunk(chunkX, chunkY + 1).getHoopla(x, 0);
				this.addHooplaToBrodersMeshVertices(vertices, colors, hoopla, x + toAddX, Chunk.SIZE + toAddY, index);
				index += 3;
			}
		
			if (borderX == false)
			{
				hoopla = map.getChunk(chunkX + 1, chunkY).getHoopla(0, Chunk.SIZE - 1);
				this.addHooplaToBrodersMeshVertices(vertices, colors, hoopla, Chunk.SIZE + toAddX, Chunk.SIZE - 1 + toAddY, index);
				index += 3;
				
				hoopla = map.getChunk(chunkX + 1, chunkY + 1).getHoopla(0, 0);
				this.addHooplaToBrodersMeshVertices(vertices, colors, hoopla, Chunk.SIZE + toAddX, Chunk.SIZE + toAddY, index);
				index += 3;
			}
		}
		
		if (borderX == false)
		{
			for (y = 0; y < Chunk.SIZE; ++y)
			{
				hoopla = map.getChunk(chunkX, chunkY).getHoopla(Chunk.SIZE - 1, y);
				this.addHooplaToBrodersMeshVertices(vertices, colors, hoopla, Chunk.SIZE - 1 + toAddX, y + toAddY, index);
				index += 3;
				
				hoopla = map.getChunk(chunkX + 1, chunkY).getHoopla(0, y);
				this.addHooplaToBrodersMeshVertices(vertices, colors, hoopla, Chunk.SIZE + toAddX, y + toAddY, index);
				index += 3;
			}
		
			if (borderY == false)
			{
				hoopla = map.getChunk(chunkX, chunkY + 1).getHoopla(Chunk.SIZE - 1, 0);
				this.addHooplaToBrodersMeshVertices(vertices, colors, hoopla, Chunk.SIZE - 1 + toAddX, Chunk.SIZE + toAddY, index);
				index += 3;
				
				hoopla = map.getChunk(chunkX + 1, chunkY + 1).getHoopla(0, 0);
				this.addHooplaToBrodersMeshVertices(vertices, colors, hoopla, Chunk.SIZE + toAddX, Chunk.SIZE + toAddY, index);
				index += 3;
			}
		}
	}

	private void	addChunkToBordersMeshIndices(int[] indices, int index, boolean borderX, boolean borderY)
	{
		int			i;
		int			x, y;
		
		if (borderX == false)
		{
			x = Chunk.SIZE;
			if (borderY)
			{
				--x;
			}
			
			for (i = 0; i < x; ++i)
			{
				indices[index + 0] = 0 + index / 3;
				indices[index + 1] = 1 + index / 3;
				indices[index + 2] = 2 + index / 3;
				indices[index + 3] = 3 + index / 3;
				indices[index + 4] = 1 + index / 3;
				indices[index + 5] = 2 + index / 3;
				
				index += 6;
			}
			
			index += 6;
		}

		if (borderY == false)
		{
			y = Chunk.SIZE;
			if (borderX)
			{
				--y;
			}
			for (i = 0; i < y; ++i)
			{
				indices[index + 0] = 0 + index / 3;
				indices[index + 1] = 1 + index / 3;
				indices[index + 2] = 2 + index / 3;
				indices[index + 3] = 3 + index / 3;
				indices[index + 4] = 1 + index / 3;
				indices[index + 5] = 2 + index / 3;
				
				index += 6;
			}
		}
	}

	private void	createChunksBorders(Map map)
	{
		float		vertices[];
		float		colors[];
		int			indices[];
		int			casesNumber;
		int			x, y;
		int			vertexIndex, indicesIndex;
		
		casesNumber = map.getChunksNumber() * (Chunk.SIZE + Chunk.SIZE + 2);
		vertices = new float[2 * 3 * casesNumber];
		colors = new float[2 * 3 * casesNumber];
		indices = new int[6 * casesNumber];
		vertexIndex = 0;
		indicesIndex = 0;
		
		for (x = 0; x < map.getLonger(); ++x)
		{
			for (y = 0; y < map.getLarger(); ++y)
			{
				this.addChunkToBordersMeshVertices(vertices, colors, map, x, y, vertexIndex, x == map.getLonger() - 1, y == map.getLarger() - 1);
				this.addChunkToBordersMeshIndices(indices, indicesIndex, x == map.getLonger() - 1, y == map.getLarger() - 1);
				
				vertexIndex += 6 * (Chunk.SIZE + Chunk.SIZE + 2);
				indicesIndex += 6 * (Chunk.SIZE + Chunk.SIZE + 2);
			}
		}
		
		chunksBorders = new Mesh();
		chunksBorders.addVertices(vertices);
		chunksBorders.addColors(colors);
		chunksBorders.addIndices(indices);
		chunksBorders.build();
	}
	
	@Override
	public void		manageData(long elapsedTime)
	{
		Map			map;
		
		super.manageData(elapsedTime);
		if (chunksBorders == null)
		{
			map = DataManager.getInstance().getMap();
			if (map != null && map.isReady())
			{
				this.createChunksBorders(map);
			}
		}
	}

	private void prepareEventsHandler()
	{
		eventsHandler = new EventsHandler();
		eventsHandler.addKeyboardEvent(Keyboard.KEY_UP,		new HelicopterCameraMoveFrontListener(camera));
		eventsHandler.addKeyboardEvent(Keyboard.KEY_DOWN,	new HelicopterCameraMoveBackListener(camera));
		eventsHandler.addKeyboardEvent(Keyboard.KEY_RIGHT,	new HelicopterCameraRotateRightListener(camera));
		eventsHandler.addKeyboardEvent(Keyboard.KEY_LEFT,	new HelicopterCameraRotateLeftListener(camera));
		eventsHandler.addKeyboardEvent(Keyboard.KEY_F3,		new BooleanSwitchListener(grid)); // useless now
	}
}
