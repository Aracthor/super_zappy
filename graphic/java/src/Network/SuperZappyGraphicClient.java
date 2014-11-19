package Network;

import java.util.HashMap;

import Commands.ACommand;
import Commands.CASCommand;
import Commands.CHKCommand;
import Commands.EmptyCommand;
import Commands.ISLCommand;
import Commands.KickCommand;
import Commands.MSGCommand;
import Commands.PDCCommand;
import Commands.PDGCommand;
import Commands.PEQCommand;
import Commands.PPOCommand;
import Commands.RESCommand;
import Commands.TDCCommand;
import Data.Chunk;
import Data.DataManager;
import Data.Map;
import Debug.DebugLog;

public class SuperZappyGraphicClient extends AClient
{
	private	HashMap<String, ACommand>	commands;
	private int							longer;
	private int							larger;
	private boolean						waitingAChunk;
	private boolean						inited;
	private boolean[][]					chunksPos;
	
	public SuperZappyGraphicClient(String host, String port)
	{
		super(host, port);
		
		commands = new HashMap<String, ACommand>();
		commands.put("WELCOME", new EmptyCommand());
		commands.put("CAS", new CASCommand());
		commands.put("CHK", new CHKCommand());
		commands.put("ISL", new ISLCommand());
		commands.put("MSG", new MSGCommand());
		commands.put("PDC", new PDCCommand());
		commands.put("PDG", new PDGCommand());
		commands.put("PEQ", new PEQCommand());
		commands.put("PPO", new PPOCommand());
		commands.put("RES", new RESCommand());
		commands.put("TDC", new TDCCommand());
		commands.put("GET", new KickCommand());
		waitingAChunk = false;
		inited = false;
		chunksPos = null;
		
		this.send("GRAPHIC");
	}
	
	private void	initData(int longer, int larger)
	{
		int		x, y;
		
		this.longer = longer;
		this.larger = larger;
		chunksPos = new boolean[larger][longer];
		
		for (x = 0; x < longer; ++x)
		{
			for (y = 0; y < larger; ++y)
			{
				chunksPos[y][x] = false;
			}
		}
		
		inited = true;
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
		
		if (x <= longer - 1 || y <= larger - 1 || chunksPos[y][x] == false)
		{
			this.askForChunk(x, y);
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
				if (chunk != null)
				{
					if (chunk.isReady() && chunksPos[y][x] == false)
					{
						chunksPos[y][x] = true;
						found = true;
					}
				}
			}
		}
		
		return (found);
	}
	
	private void	lookForChunks()
	{
		Map		map = DataManager.getInstance().getMap();
		
		if (map != null)
		{
			if (waitingAChunk == true)
			{
				waitingAChunk = !this.checkForNewChunks(map);
			}
			if (waitingAChunk == false && map.isReady() == false)
			{
				this.askForChunk();
				waitingAChunk = true;
			}
		}
	}
	
	private void	tryToInit()
	{
		Map			map = DataManager.getInstance().getMap();
		
		if (map != null && inited == false)
		{
			this.initData(map.getLonger(), map.getLarger());
		}
	}
	
	@Override
	public void	recvPacket(String line)
	{
		String[]	args;
		ACommand	command;
		
		DebugLog.getInstance().std.print("Packet received : " + line);
		args = line.split(" ");
		
		command = commands.get(args[0]);
		if (command == null)
		{
			DebugLog.getInstance().err.print("Unknown command " + args[0]);
		}
		else
		{
			loop = command.tryToExecute(args);
			this.tryToInit();
			this.lookForChunks();
		}
	}

	
	public void	askForChunk(int x, int y)
	{
		this.send("CHK " + x + " " + y);
	}
	
	
	public boolean isLooping()
	{
		return (loop);
	}
}
