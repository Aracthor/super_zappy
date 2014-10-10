package Commands;

public abstract class ACommand
{
	public	ACommand()
	{
	}
	
	public void	tryToExecute(String[] args)
	{
		this.execute(args);
	}
	
	protected abstract void	execute(String[] args);
}
