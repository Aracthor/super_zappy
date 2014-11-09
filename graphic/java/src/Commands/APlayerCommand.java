package Commands;

import Data.DataManager;
import Data.Player;
import Debug.DebugLog;

public abstract class APlayerCommand extends APreciseCommand
{
	public	APlayerCommand(int number)
	{
		super(number);
	}
	
	@Override
	protected boolean	execute(String[] args)
	{
		Player			player;
		boolean			valid;
		
		player = DataManager.getInstance().getPlayer(args[1]);
		valid = (player != null);
		
		if (valid)
		{
			valid = this.applyOnPlayer(player, args);
		}
		else
		{
			DebugLog.getInstance().err.print("Request " + args[0] + " for unexistant player " + args[1] + '.');
		}
		
		return (valid);
	}

	protected abstract boolean	applyOnPlayer(Player player, String[] args);
}
