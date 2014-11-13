package Graphics.Relief;

import org.lwjgl.util.vector.Vector2f;
import org.lwjgl.util.vector.Vector3f;

import Core.Application;
import Data.DataManager;
import Data.Player;
import Data.Team;
import Engine.Models.Mesh;
import Graphics.AGraphicPlayer;
import Graphics.GraphicWarehouse;

public class ReliefGraphicPlayer extends AGraphicPlayer
{
	private	Mesh		mesh;
	private	Mesh		equipementMesh;
	private Vector3f	color;
	
	public ReliefGraphicPlayer(Player data)
	{
		mesh = GraphicWarehouse.getInstance().getModel("pawn");
		color = this.getPlayerColor(data.getTeam());
		this.update(data);
	}
	
	private Vector3f	getPlayerColor(Team team)
	{
		final int		DEFAULT_COLORS_NUMBER = 6;
		DataManager		dataManager = DataManager.getInstance();
		Vector3f		colors[] = new Vector3f[DEFAULT_COLORS_NUMBER];
		
		colors[0] = new Vector3f(1.0f, 0.0f, 0.0f);
		colors[1] = new Vector3f(0.0f, 1.0f, 0.0f);
		colors[2] = new Vector3f(0.0f, 0.0f, 1.0f);
		colors[3] = new Vector3f(1.0f, 1.0f, 0.0f);
		colors[4] = new Vector3f(1.0f, 0.0f, 1.0f);
		colors[5] = new Vector3f(0.0f, 1.0f, 1.0f);
		
		return (colors[dataManager.getTeamId(team) % DEFAULT_COLORS_NUMBER]);
	}
	
	
	@Override
	public void 	update(Player data)
	{
		Vector2f	position;
		float		z;
		
		position = data.getPosition();
		z = DataManager.getInstance().getMap().getHoopla(position.x, position.y).getHeight();
		
		mesh.setPosition(position.x, position.y, z / 10.0f);
		mesh.setRotation(0.0f, 0.0f, data.getOrientation() * 90.0f);
		
		equipementMesh = data.getEquipement().get3DModel();
		if (equipementMesh != null)
		{
			equipementMesh.setPosition(position.x, position.y, z / 10.0f + 4.0f);
			equipementMesh.setRotation(30.0f, 0.0f, Application.getTotalElapsedTime() / 2.0f);
		}
	}
	
	@Override
	public void display(long elapsedTime)
	{
		mesh.setBaseColor(color);
		mesh.draw();
		
		if (equipementMesh != null)
		{
			equipementMesh.draw();
		}
	}
}
