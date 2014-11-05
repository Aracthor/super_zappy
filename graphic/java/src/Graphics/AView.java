package Graphics;

import java.util.Iterator;
import java.util.Vector;

import Data.Chunk;
import Data.DataManager;
import Data.Map;
import Events.EventsHandler;

public abstract class AView
{
	public static int	VIEWS_NUMBER = 2;
	
	protected Vector<AGraphicChunk>		chunks;
	protected int						longer, larger;
	protected boolean[][]				chunksPos;
	protected boolean					inited;
	
	
	protected	EventsHandler	eventsHandler;
	
	public	AView()
	{
		chunks = new Vector<AGraphicChunk>();
		chunksPos = null;
		inited = false;
	}
	
	
	public void	initData(int longer, int larger)
	{
		int		x, y;
		
		this.longer = longer;
		this.larger = larger;
		chunks.setSize(longer * larger);
		chunksPos = new boolean[larger][longer];
		
		for (x = 0; x < longer; ++x)
		{
			for (y = 0; y < larger; ++y)
			{
				chunksPos[y][x] = false;
			}
		}
	}
	
	
	public void	handleEvents(long elapsedTime)
	{
		eventsHandler.listen(elapsedTime);
	}
	
	
	protected void	displayAllChunks(long elapsedTime)
	{
		Iterator<AGraphicChunk>	it;
		AGraphicChunk			chunk;
		
		for (it = chunks.iterator(); it.hasNext();)
		{
			chunk = it.next();
			if (chunk != null)
			{
				chunk.display(elapsedTime, false);
			}
		}
	}
	
	protected void	displaySomeChunks(long elapsedTime, IChunkSorter sorter)
	{
		Iterator<AGraphicChunk>	it;
		AGraphicChunk			chunk;
		
		for (it = chunks.iterator(); it.hasNext();)
		{
			chunk = it.next();
			if (chunk != null && sorter.judgeChunk(chunk) == true)
			{
				chunk.display(elapsedTime, true);
			}
		}
	}
	
	private boolean	checkForNewChunks(Map map)
	{
		Chunk		chunk;
		int			x, y;
		boolean		found;
		
		found = false;
		for (x = 0; x < map.getLonger(); ++x)
		{
			for (y = 0; y < map.getLarger(); ++y)
			{
				chunk = map.getChunk(x, y);
				if (chunk != null && chunks != null)
				{
					if (chunk.isReady() && chunksPos[y][x] == false)
					{
						chunksPos[y][x] = true;
						chunks.add(this.createGraphicChunk(x, y, chunk));
						found = true;
					}
				}
			}
		}
		
		return (found);
	}

	public void	manageData(long elapsedTime)
	{
		Map		map = DataManager.getInstance().getMap();
		
		if (map != null)
		{
			this.checkForNewChunks(map);
		}
	}
	
	public void	select()
	{
		Map		map = DataManager.getInstance().getMap();
		
		if (map != null)
		{
			this.checkForNewChunks(map);
		}
	}

	protected abstract AGraphicChunk	createGraphicChunk(int x, int y, Chunk chunk);
	public abstract void				display(long elapsedTime);
}
