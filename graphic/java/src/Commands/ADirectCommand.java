package Commands;

public abstract class ADirectCommand extends ACommand
{
	public ADirectCommand()
	{
	}

	@Override
	protected boolean execute(String[] args)
	{
		boolean		correct;
		
		correct = (args.length == 1);
		if (correct)
		{
			correct = this.execute();
		}
		return (correct);
	}
	
	protected abstract boolean	execute();
}
