package Commands;

import Data.DataManager;

public class ISLCommand extends APreciseCommand {
	
	public	ISLCommand()
	{
		super(4);
	}

	@Override
	protected void execute(String[] args)
	{
		DataManager	dataManager = DataManager.getInstance();
		
		dataManager.prepare(Integer.parseInt(args[1]), Integer.parseInt(args[2]), Integer.parseInt(args[3]));
	}

}
