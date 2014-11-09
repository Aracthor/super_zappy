package Commands;

import Data.EItem;
import Data.Player;

public class PEQCommand extends APlayerCommand
{
	public PEQCommand()
	{
		super(3);
	}

	@Override
	protected boolean applyOnPlayer(Player player, String[] args)
	{
		player.setEquipement(EItem.getFromId(Integer.parseInt(args[2])));
		return true;
	}
}
