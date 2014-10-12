package Data;

import java.util.Vector;

public class DataManager
{
	private static	DataManager	s_instance = null;
	
	public static	DataManager	getInstance()
	{
		if (s_instance == null)
			s_instance = new DataManager();
		return (s_instance);
	}
	
	
	private	Map				map;
	private int				speed;
	private Vector<Team>	teams;
	private Vector<Player>	players;
	
	private	DataManager()
	{
		map = null;
		speed = 0;
		teams = new Vector<Team>();
		players = new Vector<Player>();
	}
	
	
	public void	prepare(int speed, int map_longer, int map_larger)
	{
		System.out.println("yolo");
		this.speed = speed;
		this.map = new Map(map_longer, map_larger);
	}
	
	public void	addTeam(Team team)
	{
		teams.add(team);
	}
	
	public void	addPlayer(Player player)
	{
		players.add(player);
	}
	
	
	public Map	getMap()
	{
		return (map);
	}
	
	public int	getSpeed()
	{
		return (speed);
	}
}
