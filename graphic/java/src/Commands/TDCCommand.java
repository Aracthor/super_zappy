package Commands;

import Data.DataManager;
import Data.Team;

public class TDCCommand extends APreciseCommand
{
	public	TDCCommand()
	{
		super(3);
	}

	@Override
	protected void execute(String[] args)
	{
		DataManager	dataManager = DataManager.getInstance();
		Team		new_team;
		
		new_team = new Team(args[2]);
		dataManager.addTeam(new_team);
	}

}
