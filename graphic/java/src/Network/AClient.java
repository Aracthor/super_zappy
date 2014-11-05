package Network;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.net.Socket;

import Debug.DebugLog;
import Exceptions.ConnectionException;
import Exceptions.ExitException;
import Exceptions.LaunchException;

public abstract class AClient
{
	private	Socket				socket;
	private InputStream			input;
	private OutputStream		output;
	private BufferedReader		buffer;
	private InputStreamReader	isr;
	
	protected boolean			loop;
	
	public	AClient(String host, String port) throws LaunchException
	{
		try
		{
			socket = new Socket(host, Integer.parseInt(port));
			input = socket.getInputStream();
			output = socket.getOutputStream();
			isr = new InputStreamReader(input);
			buffer = new BufferedReader(isr);
		}
		catch (Exception exception)
		{
			throw new ConnectionException();
		}
		
		loop = true;
	}
	
	
	private void	send(byte[] bytes)
	{
		try
		{
			output.write(bytes);
			output.flush();
		}
		catch (IOException exception)
		{
			DebugLog.getInstance().err.print("Error writing data on socket : " + exception.getMessage());
		}
	}
	
	public void	send(String data)
	{
		DebugLog.getInstance().std.print("Message sent : " + data);
		data += '\n';
		this.send(data.getBytes());
	}
	
	
	public void	recv()
	{
		String	line;
		
		try
		{
			while (loop == true && (line = buffer.readLine()) != null)
			{
				this.recvPacket(line);
			}
		}
		catch (IOException exception)
		{
			if (socket.isClosed() == false)
			{
				DebugLog.getInstance().err.print("Error receiving data : " + exception.getMessage());
			}
		}
	}
	
	
	public void	disconnect() throws ExitException
	{
		try
		{
			socket.shutdownInput();
			socket.shutdownOutput();
			socket.close();
			input.close();
			output.close();
			buffer.close();
			isr.close();
		}
		catch (Exception exception)
		{
			throw new ExitException("Error disconnecting : " + exception.getMessage());
		}
	}
	
	
	abstract void	recvPacket(String line);
}
