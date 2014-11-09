package Data;

import Debug.DebugLog;

public class Team
{
	private final	String	name;
	private boolean			discalified;

	public	Team(String name, boolean discalified)
	{
		this.name = name;
		this.discalified = discalified;
	}
	
	public	String	getName()
	{
		return (name);
	}
	
	public boolean	isDiscalified()
	{
		return (discalified);
	}
	
	
	public void		discalify()
	{
		discalified = true;
		DebugLog.getInstance().events.print("Team " + name + " is discalified !");
	}
}
