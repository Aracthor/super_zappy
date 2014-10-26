package Events;

import Usefull.Pointer;

public class BooleanSwitchListener implements IListener
{
	private Pointer<Boolean>	bool;
	
	public BooleanSwitchListener(Pointer<Boolean> bool)
	{
		this.bool = bool;
	}
	
	@Override
	public boolean hear(long elapsedTime)
	{
		bool.setData(!bool.getData());
		
		return true;
	}

}
