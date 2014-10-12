package Commands;

import Data.DataManager;

public class CHKCommand extends APreciseCommand
{
	public	CHKCommand()
	{
		super(3);
	}

	@Override
	protected void execute(String[] args)
	{
		DataManager	dataManager = DataManager.getInstance();
		int	x, y;
		
		x = Integer.parseInt(args[1]);
		y = Integer.parseInt(args[2]);
		dataManager.getMap().addChunk(x, y);
	}
}
