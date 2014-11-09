package Graphics.Relief;

import org.lwjgl.util.vector.Vector3f;

import Data.Chunk;
import Data.Hoopla;
import Engine.Models.Mesh;
import Graphics.AGraphicChunk;

public class						ReliefGraphicChunk extends AGraphicChunk
{
	private Mesh					ground;
	
	public			ReliefGraphicChunk(int x, int y, Chunk chunk)
	{
		super(chunk, x, y);
		this.createGround(x, y);
	}
	
	private void	createGround(int x, int y)
	{
		float		vertices[];
		float		colors[];
		int			indices[];
		
		vertices = new float[Chunk.SIZE * Chunk.SIZE * 3];
		colors = new float[Chunk.SIZE * Chunk.SIZE * 3];
		indices = new int[Chunk.SIZE * Chunk.SIZE * 6];
		this.addChunkToVertices(vertices, colors, x, y);
		this.addChunkToIndices(indices);
		
		this.createMesh(vertices, colors, indices);
	}
	
	private void	addChunkToVertices(float vertices[], float colors[], int chunkX, int chunkY)
	{
		Hoopla		hoopla;
		int			x, y;
		int			index;
		
		chunkX *= Chunk.SIZE;
		chunkY *= Chunk.SIZE;
		
		index = 0;
		for (x = 0; x < Chunk.SIZE; ++x)
		{
			for (y = 0; y < Chunk.SIZE; ++y)
			{
				hoopla = data.getHoopla(x, y);
				this.addHooplaToVertices(vertices, colors, hoopla, chunkX + x, chunkY + y, index);
				index += 3;
			}
		}
	}
	
	private void	addHooplaToVertices(float vertices[], float colors[], Hoopla hoopla, int x, int y, int index)
	{
		Vector3f	color;
		float		height;
		
		color = hoopla.getGroundType().getColor();
		height = hoopla.getHeight() / 10.0f;
		
		vertices[index +  0] = x;
		vertices[index +  1] = y;
		vertices[index +  2] = height;

		colors[index + 0] = color.x;
		colors[index + 1] = color.y;
		colors[index + 2] = color.z;
	}
	
	private void	addChunkToIndices(int[] indices)
	{
		int			x, y;
		int			index;
		
		index = 0;
		
		for (x = 0; x < Chunk.SIZE; ++x)
		{
			for (y = 0; y < Chunk.SIZE; ++y)
			{
				if (x != Chunk.SIZE - 1 && y != Chunk.SIZE - 1)
				{
					indices[index + 0] = 0 + index / 6;
					indices[index + 1] = 1 + index / 6;
					indices[index + 2] = Chunk.SIZE + index / 6;
					indices[index + 3] = Chunk.SIZE + 1 + index / 6;
					indices[index + 4] = 1 + index / 6;
					indices[index + 5] = Chunk.SIZE + index / 6;
				}
				
				index += 6;
			}
		}
	}
	
	private void	createMesh(float vertices[], float colors[], int indices[])
	{
		ground = new Mesh();
		ground.addVertices(vertices);
		ground.addColors(colors);
		ground.addIndices(indices);
		ground.build();
	}
	
	protected void	drawHoopla(Hoopla hoopla, int x, int y, long elapsedTime)
	{
		Mesh		model;
		
		model = hoopla.getObjectType().get3DModel();
		if (model != null)
		{
			model.setPosition(x + this.x * Chunk.SIZE, y + this.y * Chunk.SIZE, hoopla.getHeight() / 10.0f);
			model.draw();
		}
	}
	
	public void drawGround()
	{
		ground.draw();
	}
}
