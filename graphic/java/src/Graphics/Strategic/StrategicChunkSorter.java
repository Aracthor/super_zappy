package Graphics.Strategic;

import Data.Chunk;
import Graphics.AGraphicChunk;
import Graphics.IChunkSorter;

public class			StrategicChunkSorter implements IChunkSorter
{
	private final float	x, y;
	
	public		StrategicChunkSorter(float x, float y)
	{
		this.x = x;
		this.y = y;
	}

	@Override
	public boolean judgeChunk(AGraphicChunk chunk)
	{
		float	limit = 90.0f;
		
		return (chunk.getPosX() * Chunk.SIZE - x < limit && chunk.getPosX() * Chunk.SIZE - x > -limit &&
				chunk.getPosY() * Chunk.SIZE - y < limit && chunk.getPosY() * Chunk.SIZE - y > -limit);
	}

}
