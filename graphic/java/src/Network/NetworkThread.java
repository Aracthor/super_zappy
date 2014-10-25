package Network;

import Debug.DebugLog;

public class NetworkThread extends Thread
{
	private SuperZappyClient	client;
	private	boolean				running;
	
	public	NetworkThread(String host, String port)
	{
		super();
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
	
	
	public void	askForChunks()
	{
		client.askForChunks();
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
