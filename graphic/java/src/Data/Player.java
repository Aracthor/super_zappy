package Data;

public class Player
{
	String	name;
	int		teamId;
	
	public	Player(String name, int teamId)
	{
		this.name = name;
		this.teamId = teamId;
	}
	
	
	public String	getName()
	{
		return (name);
	}
	
	public int		getTeamId()
	{
		return (teamId);
	}
}
