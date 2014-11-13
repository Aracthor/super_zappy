package Commands;

import Data.Player;

public class PPOCommand extends APlayerCommand
{
	public PPOCommand()
	{
		super(5);
	}

	@Override
	protected boolean applyOnPlayer(Player player, String[] args)
	{
		player.setPosition(Integer.parseInt(args[2]), Integer.parseInt(args[3]));
		player.setOrientation(Integer.parseInt(args[4]));
		return true;
	}
}
