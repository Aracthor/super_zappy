package Data;

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
}
