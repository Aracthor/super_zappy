package Data;

import org.lwjgl.util.vector.Vector2f;

public class Player
{
	String		name;
	String		className;
	Team		team;
	Vector2f	position;
	int			orientation;
	EItem		equipement;
	
	public	Player(String name, int posX, int posY, Team team, String className, EItem equipement)
	{
		this.name = name;
		this.className = className;
		this.position = new Vector2f(posX, posY);
		this.team = team;
		this.equipement = equipement;
	}
	
	
	public String	getName()
	{
		return (name);
	}
	
	public Team		getTeam()
	{
		return (team);
	}
	
	public Vector2f	getPosition()
	{
		return (position);
	}
	
	public int		getOrientation()
	{
		return (orientation);
	}
	
	
	public void		setPosition(int x, int y)
	{
		this.position.x = x;
		this.position.y = y;
	}
	
	public void		setOrientation(int orientation)
	{
		this.orientation = orientation;
	}
	
	public void		setEquipement(EItem equipement)
	{
		this.equipement = equipement;
	}
}
