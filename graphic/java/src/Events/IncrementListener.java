package Events;

import Engine.Clock;

public class IncrementListener implements IListener
{
	private final IncrementableEnum	refEnum;
	private final Clock				clock;
	
	public IncrementListener(IncrementableEnum refEnum)
	{
		this.refEnum = refEnum;
		this.clock = new Clock();
	}
	
	@Override
	public boolean hear(long elapsedTime)
	{
		clock.update();
		if (clock.getTotalElapsedTime() > 1000)
		{
			refEnum.increment();
			clock.reset();
		}
		
		return true;
	}
}
