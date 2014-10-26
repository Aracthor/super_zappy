package Graphics;

import Data.Chunk;
import Data.Hoopla;

public abstract class AGraphicChunk
{
	protected final	Chunk	data;
	protected final int		x, y;
	
	public AGraphicChunk(Chunk chunk, int x, int y)
	{
		data = chunk;
		this.x = x;
		this.y = y;
	}
	
	public void	display(long elapsedTime, boolean showDetails)
	{
		int		x, y;
		
		this.drawGround();
		
		if (showDetails)
		{
			for (x = 0; x < Chunk.SIZE; ++x)
			{
				for (y = 0; y < Chunk.SIZE; ++y)
				{
					this.drawHoopla(data.getHoopla(x, y), x, y, elapsedTime);
				}
			}
		}
	}
	
	public int	getPosX()
	{
		return (x);
	}
	
	public int	getPosY()
	{
		return (y);
	}
	
	protected abstract void	drawGround();
	protected abstract void	drawHoopla(Hoopla hoopla, int x, int y, long elapsedTime);
}
