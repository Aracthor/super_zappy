package Debug;

public class DebugLog
{
	private static DebugLog	s_instance = null;
	
	public static DebugLog	getInstance()
	{
		if (s_instance == null)
			s_instance = new DebugLog();
		return (s_instance);
	}
	
	
	public	ILog	std;
	public	ILog	err;
	
	private	DebugLog()
	{
		std = new StandartLog();
		err = new ErrorLog();
	}
}
