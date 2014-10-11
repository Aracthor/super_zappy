package Network;

import java.util.HashMap;

import Commands.ACommand;
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
		commands.put("ISL", new ISLCommand());
		commands.put("TDC", new TDCCommand());
		
		this.send("GRAPHICAL");
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

}