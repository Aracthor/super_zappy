package Commands;

import Data.DataManager;

public class TIMCommand extends APreciseCommand
{
	public	TIMCommand()
	{
		super(2);
	}
	
	@Override
	protected boolean	execute(String[] args)
	{
		int				newTime;
		boolean			valid;
		
		newTime = Integer.parseInt(args[1]);
		valid = (newTime > 0);
		
		if (valid)
		{
			DataManager.getInstance().setSpeed(newTime);
		}
		
		return (valid);
	}

}
