package Commands;

import Debug.DebugLog;

public class	CHTCommand extends ACommand
{
	public		CHTCommand()
	{
		super();
	}
	
	@Override
	protected boolean	execute(String[] args)
	{
		boolean			valid;
		
		valid = (args.length > 2);
		if (valid)
		{
			DebugLog.getInstance().events.print("Team " + args[1] + " has cheated : " + args[2]);
		}
		return (valid);
	}
}
