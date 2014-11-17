package Commands;

import Debug.DebugLog;

public class MSGCommand extends ACommand
{
	public MSGCommand()
	{
	}
	
	@Override
	protected boolean	execute(String[] args)
	{
		String			message;
		int				i;
		boolean			valid;
		
		valid = (args.length >= 3);
		if (valid)
		{
			message = args[2];
			for (i = 3; i < args.length; ++i)
			{
				message += " " + args[i];
			}
			DebugLog.getInstance().events.print("Mail of player " + args[1] + " : " + message);
		}
		
		return valid;
	}

}
