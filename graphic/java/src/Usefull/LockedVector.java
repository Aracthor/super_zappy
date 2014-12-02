package Usefull;

import java.util.Vector;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class LockedVector<T> extends Vector<T>
{
	private static final long serialVersionUID = 1L;
	
	
	private Lock	lock;

	public	LockedVector()
	{
		super();
		lock = new ReentrantLock();
	}
	
	public boolean	add(T elem)
	{
		boolean		added;
		
		this.lock();
		{
			added = super.add(elem);
		}
		this.unlock();
		
		return (added);
	}
	
	public	void	lock()
	{
		lock.lock();
	}
	
	public	void	unlock()
	{
		lock.unlock();
	}
}
