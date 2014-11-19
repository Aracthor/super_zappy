package Commands;

import Data.EAction;
import Data.Player;
import Data.PlayerAction;

public class PDGCommand extends APlayerCommand
{
	public	PDGCommand()
	{
		super(3);
	}

	@Override
	protected boolean applyOnPlayer(Player player, String[] args)
	{
		int		time = Integer.parseInt(args[2]);
		
		player.setAction(new PlayerAction(EAction.Digging, time));
		
		return true;
	}
}
