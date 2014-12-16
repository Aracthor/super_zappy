package Commands;

import Data.Player;
import Data.PlayerAction;

public abstract class APlayerActionCommand extends APlayerCommand
{
	public	APlayerActionCommand(int argsNumber)
	{
		super(argsNumber);
	}

	@Override
	protected boolean applyOnPlayer(Player player, String[] args)
	{
		PlayerAction	action;
		int				time = Integer.parseInt(args[2]);
		boolean			valid;
		
		action = this.createAction(time, args);
		valid = (action != null);

		if (valid)
		{
			player.setAction(action);
		}
		
		return (valid);
	}
	
	protected abstract PlayerAction	createAction(int time, String[] args);
}
