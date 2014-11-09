package Graphics;

import java.util.HashMap;
import java.util.Iterator;
import java.util.Vector;

import Data.Chunk;
import Data.DataManager;
import Data.Map;
import Data.Player;
import Engine.GlControlPanel;
import Engine.Camera.ACamera;
import Events.EventsHandler;

public abstract class AView
{
	public static int	VIEWS_NUMBER = 2;
	
	protected ACamera							camera;
	protected HashMap<Player, AGraphicPlayer>	players;
	protected Vector<AGraphicChunk>				chunks;
	protected int								longer, larger;
	protected boolean[][]						chunksPos;
	protected boolean							inited;
	
	
	protected	EventsHandler	eventsHandler;
	
	public	AView()
	{
		players = new HashMap<Player, AGraphicPlayer>();
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
	
	private void			displayPlayer(Player player, long elapsedTime)
	{
		AGraphicPlayer		graphicPlayer = players.get(player);
		
		if (graphicPlayer == null)
		{
			graphicPlayer = this.createGraphicPlayer(player);
			players.put(player, graphicPlayer);
		}
		else
		{
			graphicPlayer.update(player);
		}
		graphicPlayer.display();
	}
	
	public void				display(long elapsedTime)
	{
		DataManager			dataManager;
		Vector<Player>		players;
		Iterator<Player>	playerIt;
		
		dataManager = DataManager.getInstance();
		players = dataManager.getPlayers();
		
		GlControlPanel.getInstance().initFrame(camera);
		{
			this.displayChunks(elapsedTime);
			DataManager.getInstance().getLock().lock();
			{
				for (playerIt = players.iterator(); playerIt.hasNext();)
				{
					this.displayPlayer(playerIt.next(), elapsedTime);
				}
			}
			DataManager.getInstance().getLock().unlock();
		}
		GlControlPanel.getInstance().endFrame();
	}

	protected abstract AGraphicPlayer	createGraphicPlayer(Player player);
	protected abstract AGraphicChunk	createGraphicChunk(int x, int y, Chunk chunk);
	protected abstract void				displayChunks(long elapsedTime);
}
