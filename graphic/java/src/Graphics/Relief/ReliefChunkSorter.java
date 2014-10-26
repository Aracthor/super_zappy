package Graphics.Relief;

import Data.Chunk;
import Engine.Camera.HelicopterCamera;
import Graphics.AGraphicChunk;
import Graphics.IChunkSorter;

public class						ReliefChunkSorter implements IChunkSorter
{
	private final HelicopterCamera	camera;
	
	public		ReliefChunkSorter(HelicopterCamera camera)
	{
		this.camera = camera;
	}
	
	private boolean	isInRange(AGraphicChunk chunk, float distanceX, float distanceY)
	{
		float		limit = 130.0f;
		
		return (Math.abs(distanceX) < limit && Math.abs(distanceY) < limit);
	}
	
	private boolean	isInFront(AGraphicChunk chunk, float distanceX, float distanceY)
	{
		boolean		inFront;
		
		if (distanceX > 0.0f && distanceY > 0.0f)
		{
			inFront = (camera.getAngleX() < 135.0f || camera.getAngleX() > 225.0f);
		}
		else if (distanceX < 0.0f && distanceY > 0.0f)
		{
			inFront = (camera.getAngleX() < 225.0f || camera.getAngleX() > 315.0f);
		}
		else if (distanceX > 0.0f && distanceY < 0.0f)
		{
			inFront = (camera.getAngleX() < 45.0f || camera.getAngleX() > 135.0f);
		}
		else
		{
			inFront = (camera.getAngleX() < 315.0f && camera.getAngleX() > 45.0f);
		}
		
		return (inFront);
	}
	
	@Override
	public boolean	judgeChunk(AGraphicChunk chunk)
	{
		float		distanceX, distanceY;
		boolean		viewed;
		
		distanceX = chunk.getPosX() * Chunk.SIZE - camera.getPosition().x;
		distanceY = chunk.getPosY() * Chunk.SIZE - camera.getPosition().y;
		viewed = this.isInRange(chunk, distanceX, distanceY);
		
		if (viewed && Math.abs(distanceX) > 16.0f && Math.abs(distanceY) > 16.0f)
		{
			viewed = this.isInFront(chunk, distanceX, distanceY);
		}
		
		return (viewed);
	}

}
