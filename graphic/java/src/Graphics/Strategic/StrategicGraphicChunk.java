package Graphics.Strategic;

import org.lwjgl.util.vector.Vector3f;

import Data.Chunk;
import Data.Hoopla;
import Engine.Models.Mesh;
import Graphics.AGraphicChunk;
import Graphics.GraphicWarehouse;

public class 		StrategicGraphicChunk extends AGraphicChunk
{
	private Mesh	ground;
	
	public	StrategicGraphicChunk(int x, int y, Chunk chunk)
	{
		super(chunk, x, y);
		this.createGround(x, y);
	}
	
	private void	createGround(int chunkX, int chunkY)
	{
		float		vertices[];
		float		colors[];
		int			index;
		Hoopla		hoopla;
		int			x, y;
		
		vertices = new float[Chunk.SIZE * Chunk.SIZE * 6 * 3];
		colors = new float[Chunk.SIZE * Chunk.SIZE * 6 * 3];
		chunkX *= Chunk.SIZE;
		chunkY *= Chunk.SIZE;
		index = 0;
		
		for (x = 0; x < Chunk.SIZE; ++x)
		{
			for (y = 0; y < Chunk.SIZE; ++y)
			{
				hoopla = data.getHoopla(x, y);
				this.addHooplaToVertices(vertices, colors, hoopla, chunkX + x, chunkY + y, index);
				
				index += 18;
			}
		}
		
		this.createGround(vertices, colors);
	}
	
	private void	addHooplaToVertices(float vertices[], float colors[], Hoopla hoopla, int x, int y, int index)
	{
		Vector3f	color = hoopla.getGroundType().getColor();
		int			i;
		
		vertices[index +  0] = 0;	vertices[index +  1] = y + 0;	vertices[index +  2] = x + 0;
		vertices[index +  3] = 0;	vertices[index +  4] = y + 0;	vertices[index +  5] = x + 1;
		vertices[index +  6] = 0;	vertices[index +  7] = y + 1;	vertices[index +  8] = x + 0;

		vertices[index +  9] = 0;	vertices[index + 10] = y + 1;	vertices[index + 11] = x + 1;
		vertices[index + 12] = 0;	vertices[index + 13] = y + 0;	vertices[index + 14] = x + 1;
		vertices[index + 15] = 0;	vertices[index + 16] = y + 1;	vertices[index + 17] = x + 0;

		for (i = 0; i < 18; i += 3)
		{
			colors[index +  i + 0] = color.x;	colors[index + i + 1] = color.y;	colors[index + i + 2] = color.z;
		}
	}
	
	private void	createGround(float vertices[], float colors[])
	{
		ground = new Mesh();
		ground.addVertices(vertices);
		ground.addColors(colors);
		ground.build();
	}
	
	protected void drawHoopla(Hoopla hoopla, int x, int y, long elpasedTime)
	{
		Mesh		model;
		
		model = hoopla.getObjectType().get2DModel();
		if (model != null)
		{
			model.setScale(0.8f, 0.8f, 0.8f);
			model.setPosition(0.0f, y + this.y * Chunk.SIZE + 0.1f, x + this.x * Chunk.SIZE + 0.1f);
			model.draw();
		}
	}
	
	protected void drawGround()
	{
		GraphicWarehouse.getInstance().getTexture("objects").bind();
		ground.draw();
	}
}
