package Graphics;

import Data.Player;

public abstract class AGraphicPlayer
{
	public	AGraphicPlayer()
	{
	}
	
	public abstract void	update(Player data);
	public abstract void	display(long elapsedTime);
}
