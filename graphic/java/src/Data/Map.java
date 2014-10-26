package Data;

import Debug.DebugLog;

public class Map
{
	private	int			longer;
	private	int			larger;
	private	Chunk[][]	chunks;
	private int			chunksNumber;
	
	public	Map(int longer, int larger)
	{
		this.longer = longer;
		this.larger = larger;
		chunks = new Chunk[larger][longer];
		chunksNumber = 0;
	}
	
	
	public int	getLonger()
	{
		return (longer);
	}
	
	public int	getLarger()
	{
		return (larger);
	}
	
	public Chunk	getChunk(int x, int y)
	{
		return (chunks[y][x]);
	}
	
	public int		getChunksNumber()
	{
		return (chunksNumber);
	}
	
	
	public boolean	isReady()
	{
		return (chunksNumber == longer * larger);
	}

	
	public void	addChunk(int x, int y)
	{
		chunks[y][x] = new Chunk();
	}
	
	public void	addHoopla(Hoopla hoopla, int x, int y)
	{
		Chunk	chunk;
		
		chunk = chunks[y / Chunk.SIZE][x / Chunk.SIZE];
		if (chunk == null)
		{
			DebugLog.getInstance().err.print("Map error : Trying to add a hoopla in a null chunk.");
		}
		else
		{
			chunk.setHoopla(hoopla, x % Chunk.SIZE, y % Chunk.SIZE);
			if (chunk.isReady())
			{
				++chunksNumber;
			}
		}
	}
}
