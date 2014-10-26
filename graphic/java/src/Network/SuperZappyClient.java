package Network;

import java.util.HashMap;

import Commands.ACommand;
import Commands.CASCommand;
import Commands.CHKCommand;
import Commands.EmptyCommand;
import Commands.ISLCommand;
import Commands.TDCCommand;
import Debug.DebugLog;

public class SuperZappyClient extends AClient
{
	private	HashMap<String, ACommand>	commands;
	
	public SuperZappyClient(String host, String port)
	{
		super(host, port);
		
		commands = new HashMap<String, ACommand>();
		commands.put("WELCOME", new EmptyCommand());
		commands.put("ISL", new ISLCommand());
		commands.put("TDC", new TDCCommand());
		commands.put("CHK", new CHKCommand());
		commands.put("CAS", new CASCommand());
		
		this.send("GRAPHIC");
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
			command.tryToExecute(args);
		}
	}

	
	public void	askForChunk(int x, int y)
	{
		this.send("CHK " + x + " " + y);
	}
}
