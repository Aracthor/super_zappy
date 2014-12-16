package Graphics.Relief.ActionRenderers;

import org.lwjgl.util.vector.Vector3f;

import Data.DataManager;
import Data.EItem;
import Engine.Models.Mesh;
import Graphics.Relief.ReliefGraphicPlayer;

public class AttackRenderer implements IReliefActionRenderer
{
	public	AttackRenderer()
	{
	}

	@Override
	public void		render(ReliefGraphicPlayer player, float percentage, int param, int x, int y)
	{
		Mesh		mesh = EItem.getFromId(param).get3DModel();
		Vector3f	movement;
		Vector3f	position;
		
		position = new Vector3f();
		
		movement = new Vector3f(player.getMesh().getPosition());
		movement.x -= x;
		movement.y -= y;
		movement.z -= DataManager.getInstance().getMap().getHoopla(x, y).getHeight();
		movement.scale(percentage / 100.0f);
		Vector3f.add(player.getMesh().getPosition(), movement, position);
		
		mesh.setPosition(position);
		// TODO set projectile orientation
		mesh.setRotation(0, 0, 0);
		mesh.draw();
	}

}
