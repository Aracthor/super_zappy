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
	protected boolean	execute(String[] args)
	{
		DataManager	dataManager = DataManager.getInstance();
		Team		team;
		boolean		discalified;
		
		discalified = Boolean.parseBoolean(args[2]);
		
		team = dataManager.getTeam(args[1]);
		if (team == null)
		{
			team = new Team(args[1], discalified);
			dataManager.addTeam(team);
		}
		else if (discalified)
		{
			team.discalify();
		}
		
		return (true);
	}
}
