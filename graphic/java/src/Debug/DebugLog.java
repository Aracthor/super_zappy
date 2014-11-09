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
	
	
	public final	ILog	std;
	public final	ILog	events;
	public final	ILog	init;
	public final	ILog	err;
	
	private	DebugLog()
	{
		std = new StandartLog();
		events = new EventsLog();
		init = new InitLog();
		err = new ErrorLog();
	}
}
