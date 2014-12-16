package Commands;

import Data.EAction;
import Data.PlayerAction;

public class PDGCommand extends APlayerActionCommand
{
	public	PDGCommand()
	{
		super(3);
	}

	@Override
	protected PlayerAction createAction(int time, String[] args)
	{
		return (new PlayerAction(EAction.Digging, time));
	}
}
