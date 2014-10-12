package Network;

public class NetworkThread extends Thread
{
	private SuperZappyClient	client;
	private	boolean				running;
	
	public	NetworkThread(String host, String port)
	{
		super();
		client = new SuperZappyClient(host, port);
		running = true;
	}
	
	public void	run()
	{
		while (running)
		{
			client.recv();
		}
	}
	
	public void	interrupt()
	{
		running = false;
		client.disconnect();
	}
	
	
	public void	askForChunks()
	{
		client.askForChunks();
	}
	
	public boolean	isRunning()
	{
		return (running);
	}
}
