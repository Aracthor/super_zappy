package Commands;

public abstract class ACommand
{
	public	ACommand()
	{
	}
	
	public boolean	tryToExecute(String[] args)
	{
		return (this.execute(args));
	}
	
	protected abstract boolean execute(String[] args);
}
