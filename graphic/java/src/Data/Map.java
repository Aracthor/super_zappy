package Data;

import Debug.DebugLog;

public class Map
{
	private	int			longer;
	private	int			larger;
	private	Chunk[][]	chunks;
	private boolean[][]	chunksStatus;
	private int			chunksNumber;
	private boolean		reseted;
	
	public	Map(int longer, int larger)
	{
		int	x, y;
		
		this.longer = longer;
		this.larger = larger;
		this.reseted = true;
		chunks = new Chunk[larger][longer];
		chunksStatus = new boolean[larger][longer];
		for (y = 0; y < larger; ++y)
		{
			for (x = 0; x < longer; ++x)
			{
				chunksStatus[y][x] = false;
			}
		}
			
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
	
	public boolean	isReseted()
	{
		return (reseted);
	}
	
	public Chunk	getChunk(int x, int y)
	{
		return (chunks[y][x]);
	}
	
	public Hoopla	getHoopla(int x, int y)
	{
		return (chunks[y / Chunk.SIZE][x / Chunk.SIZE].getHoopla(x % Chunk.SIZE, y % Chunk.SIZE));
	}
	
	public Hoopla	getHoopla(float x, float y)
	{
		return (this.getHoopla((int)x, (int)y));
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
			if (chunk.isReady() && chunksStatus[y / Chunk.SIZE][x / Chunk.SIZE] == false)
			{
				++chunksNumber;
				chunksStatus[y / Chunk.SIZE][x / Chunk.SIZE] = true;
			}
		}
	}
	
	public void	stopReset()
	{
		reseted = false;
	}
}
