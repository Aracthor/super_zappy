package Commands;

import Data.DataManager;
import Data.Team;

public class TDCCommand extends APreciseCommand
{
	public	TDCCommand()
	{
		super(4);
	}

	@Override
	protected boolean	execute(String[] args)
	{
		DataManager	dataManager = DataManager.getInstance();
		Team		new_team;
		
		new_team = new Team(args[2], Boolean.parseBoolean(args[3]));
		dataManager.addTeam(new_team);
		
		return (true);
	}
}
