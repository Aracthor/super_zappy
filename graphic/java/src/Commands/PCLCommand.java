package Commands;

import Data.Player;

public class PCLCommand extends APlayerCommand
{
	public	PCLCommand()
	{
		super(3);
	}

	@Override
	protected boolean applyOnPlayer(Player player, String[] args)
	{
		player.setLife(Integer.parseInt(args[2]));
		return true;
	}

}
