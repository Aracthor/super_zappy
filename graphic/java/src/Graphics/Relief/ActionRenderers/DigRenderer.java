package Graphics.Relief.ActionRenderers;

import Graphics.Relief.ReliefGraphicPlayer;

public class DigRenderer implements IReliefActionRenderer
{
	public	DigRenderer()
	{
	}
	
	@Override
	public void render(ReliefGraphicPlayer player, float percentage)
	{
		float	translation;
		
		if (percentage < 50.0f)
		{
			translation = percentage;
		}
		else
		{
			translation = (100.0f - percentage);
		}
		
		player.getMesh().translate(0.0f, 0.0f, -0.05f * translation);
	}
}
