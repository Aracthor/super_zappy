package Network;

import Debug.DebugLog;

public class NetworkThread extends Thread
{
	private static NetworkThread	s_instance = null;
	
	public static NetworkThread		getInstance()
	{
		return (s_instance);
	}
	
	
	private SuperZappyClient	client;
	private	boolean				running;
	
	public	NetworkThread(String host, String port)
	{
		super();
		s_instance = this;
		client = new SuperZappyClient(host, port);
	}
	
	public void	run()
	{
		running = true;
		
		try
		{
			client.recv();
		}
		catch (Exception exception)
		{
		}
		finally
		{
			running = false;
		}
	}
	
	@Override
	public void	interrupt()
	{
		super.interrupt();
		client.disconnect();
	}
	
	
	public void	askForChunk(int x, int y)
	{
		client.askForChunk(x, y);
	}
	
	public boolean	isRunning()
	{
		if (running == false)
		{
			DebugLog.getInstance().err.print("Connection lost.");
		}
		
		return (running);
	}
}
