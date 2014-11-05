package Commands;

import Debug.DebugLog;

public class KickCommand extends APreciseCommand
{
	public	KickCommand()
	{
		super(4);
	}

	@Override
	protected boolean	execute(String[] args)
	{
		if (args[1].equals("THE") && args[2].equals("FUCK") && args[3].equals("OUT"))
		{
			DebugLog.getInstance().err.print("Server kicked me :(");
		}
		else
		{
			DebugLog.getInstance().err.print("Server tried to kick me. I think...");
		}
		
		return (false);
	}
}
