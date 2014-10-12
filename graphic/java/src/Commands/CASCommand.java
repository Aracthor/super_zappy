package Commands;

import Data.DataManager;
import Data.Hoopla;

public class CASCommand extends APreciseCommand
{
	public	CASCommand()
	{
		super(9);
	}

	@Override
	protected void execute(String[] args)
	{
		DataManager	dataManager = DataManager.getInstance();
		Hoopla	hoopla;
		int		x, y;
		
		x = Integer.parseInt(args[1]);
		y = Integer.parseInt(args[2]);
		hoopla = new Hoopla(Integer.parseInt(args[3]), Integer.parseInt(args[4]), Integer.parseInt(args[5]), Integer.parseInt(args[6]), Integer.parseInt(args[7]));
		dataManager.getMap().addHoopla(hoopla, x, y);
	}
}
