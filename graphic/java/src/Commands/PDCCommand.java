package Commands;

import Data.DataManager;
import Data.EItem;
import Data.Player;
import Data.Team;
import Debug.DebugLog;

public class PDCCommand extends ACommand
{
	public	PDCCommand()
	{
		super();
	}

	@Override
	protected boolean execute(String[] args)
	{
		DataManager	dataManager = DataManager.getInstance();
		Player		player;
		Team		team;
		boolean		valid;
		
		valid = (args.length >= 8);

		if (valid)
		{
			player = dataManager.getPlayer(args[1]);
			if (player == null)
			{
				team = dataManager.getTeam(args[5]);
				player = new Player(args[1], Integer.parseInt(args[2]), Integer.parseInt(args[3]),
									team, args[4], EItem.getFromId(Integer.parseInt(args[7])));
				dataManager.addPlayer(player);
			}
			else
			{
				DebugLog.getInstance().err.print("Redefinition of player " + player.getName());
				valid = false;
			}
		}
		else
		{
			DebugLog.getInstance().err.print("Bad args number for command PDC.");
		}
		
		return (valid);
	}
}
