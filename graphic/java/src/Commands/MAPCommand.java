package Commands;

import Data.DataManager;
import Data.Map;

public class MAPCommand extends APreciseCommand
{
	public MAPCommand()
	{
		super(3);
	}
	
	@Override
	protected boolean	execute(String[] args)
	{
		Map				newMap;
		
		newMap = new Map(Integer.parseInt(args[1]), Integer.parseInt(args[2]));
		DataManager.getInstance().setNewMap(newMap);
		
		return true;
	}

}
