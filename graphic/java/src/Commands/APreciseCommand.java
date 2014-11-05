package Commands;

import Debug.DebugLog;

public abstract class APreciseCommand extends ACommand
{
	private	int	argsNumber;
	
	public	APreciseCommand(int argsNumber)
	{
		this.argsNumber = argsNumber;
	}
	
	@Override
	public boolean	tryToExecute(String[] args)
	{
		boolean		executed;
		
		if (args.length != argsNumber)
		{
			DebugLog.getInstance().err.print("Bad args number for command " + args[0]);
			executed = false;
		}
		else
		{
			executed = this.execute(args);
		}
		
		return (executed);
	}

}
