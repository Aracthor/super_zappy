package Commands;

import Data.DataManager;
import Debug.DebugLog;

public class RESCommand extends ADirectCommand
{
	public	RESCommand()
	{
	}
	
	@Override
	protected boolean execute()
	{
		DataManager.getInstance().reset();
		
		DebugLog.getInstance().events.print("Game reseted !");
		
		return true;
	}

}
