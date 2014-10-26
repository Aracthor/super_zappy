package Graphics;

import java.util.Iterator;
import java.util.Vector;

import Data.Chunk;
import Data.DataManager;
import Data.Map;
import Events.EventsHandler;
import Network.NetworkThread;

public abstract class AView
{
	public static int	VIEWS_NUMBER = 2;
	
	protected Vector<AGraphicChunk>		chunks;
	protected int						longer, larger;
	protected boolean[][]				chunksPos;
	protected boolean					waitingAChunk;
	protected boolean					inited;
	
	
	protected	EventsHandler	eventsHandler;
	
	public	AView()
	{
		chunks = new Vector<AGraphicChunk>();
		chunksPos = null;
		waitingAChunk = false;
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
				chunk.display(elapsedTime);
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
	
	private void	askForChunk()
	{
		int			x, y;
		
		for (x = 0, y = 0; chunksPos[y][x] == true && (x != longer - 1 || y != larger - 1);)
		{
			if (x == longer - 1)
			{
				x = 0;
				++y;
			}
			else
			{
				++x;
			}
		}
		
		if (x != longer - 1 || y != larger - 1 || chunksPos[y][x] == false)
		{
			NetworkThread.getInstance().askForChunk(x, y);
		}
	}

	public void	manageData(long elapsedTime)
	{
		Map		map = DataManager.getInstance().getMap();
		
		if (map != null)
		{
			if (waitingAChunk == true)
			{
				waitingAChunk = !this.checkForNewChunks(map);
			}
			else
			{
				this.askForChunk();
				waitingAChunk = true;
			}
		}
	}
	
	public void	select()
	{
		Map		map = DataManager.getInstance().getMap();
		
		if (map != null)
		{
			waitingAChunk = !this.checkForNewChunks(map);
		}
	}

	protected abstract AGraphicChunk	createGraphicChunk(int x, int y, Chunk chunk);
	public abstract void				display(long elapsedTime);
}
