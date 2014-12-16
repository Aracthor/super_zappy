package Commands;

import Debug.DebugLog;

public class VICCommand extends APreciseCommand
{
	public VICCommand()
	{
		super(3);
	}

	@Override
	protected boolean execute(String[] args)
	{
		DebugLog.getInstance().events.print("Victory of team " + args[1] + " by a " + args[2] + " way !");
		return true;
	}

}
