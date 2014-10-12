package Data;

public class Chunk
{
	public static final int	SIZE = 16;
	

	private Hoopla[][]	hooplas;
	private boolean		ready;

	public	Chunk()
	{
		hooplas = new Hoopla[SIZE][SIZE];
		ready = false;
	}
	
	
	private boolean	checkIfReady()
	{
		int			x, y;
		boolean		nowIsReady;
		
		nowIsReady = true;
		for (x = 0; x < SIZE && nowIsReady == true; ++x)
		{
			for (y = 0; y < SIZE && nowIsReady == true; ++y)
			{
				if (hooplas[y][x] == null)
				{
					nowIsReady = true;
				}
			}
		}
		
		return (nowIsReady);
	}
	
	public	void	setHoopla(Hoopla hoopla, int x, int y)
	{
		boolean		nowIsReady;
		
		hooplas[y][x] = hoopla;
		if (x == SIZE - 1 && y == SIZE - 1 && ready == false)
		{
			ready = this.checkIfReady();
		}
	}
	
	public Hoopla	getHoopla(int x, int y)
	{
		return (hooplas[y][x]);
	}
	
	
	public boolean	isReady()
	{
		return (ready);
	}
}
