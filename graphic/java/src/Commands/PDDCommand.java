package Commands;

import Data.Player;

public class PDDCommand extends APlayerCommand
{
	public	PDDCommand()
	{
		super(2);
	}

	@Override
	protected boolean applyOnPlayer(Player player, String[] args)
	{
		player.kill();
		return true;
	}

}
