package Data;

import java.util.Iterator;
import java.util.Vector;

public class DataManager
{
	private static	DataManager	s_instance = null;
	
	public static synchronized	DataManager	getInstance()
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
		this.speed = speed;
		this.map = new Map(map_longer, map_larger);
	}
	
	public void	reset()
	{
		this.players.clear();
	}
	
	public void	update(long elapsedTime)
	{
		Iterator<Player>	it;
		
		for (it = players.iterator(); it.hasNext();)
		{
			it.next().getAction().retireTime(elapsedTime);
		}
	}
	
	
	public void	addTeam(Team team)
	{
		teams.add(team);
	}
	
	public void	addPlayer(Player player)
	{
		players.add(player);
	}
	
	
	public Team	getTeam(String name)
	{
		Team	team;
		
		team = null;
		for (Iterator<Team> it = teams.iterator(); team == null && it.hasNext();)
		{
			team = it.next();
			if (team.getName().equals(name) == false)
			{
				team = null;
			}
		}
		
		return (team);
	}
	
	public int		getTeamId(Team team)
	{
		return (this.teams.indexOf(team));
	}
	
	public Player	getPlayer(String name)
	{
		Player	player;
		
		player = null;
		for (Iterator<Player> it = players.iterator(); player == null && it.hasNext();)
		{
			player = it.next();
			if (player.getName().equals(name) == false)
			{
				player = null;
			}
		}
		
		return (player);
	}
	
	public Vector<Player>	getPlayers()
	{
		return (players);
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
