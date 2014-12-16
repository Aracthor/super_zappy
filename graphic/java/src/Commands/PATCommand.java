package Commands;

import Data.EAction;
import Data.PlayerAction;

public class PATCommand extends APlayerActionCommand
{
	public	PATCommand()
	{
		super(6);
	}

	@Override
	protected PlayerAction	createAction(int time, String[] args)
	{
		PlayerAction		action = new PlayerAction(EAction.Attacking, time);
		
		action.setParam(Integer.parseInt(args[3]));
		action.setCoords(Integer.parseInt(args[4]), Integer.parseInt(args[5]));
		return (action);
	}
}
