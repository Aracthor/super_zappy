package Usefull;

public class Pointer<T>
{
	private T	data;
	
	public	Pointer(T data)
	{
		this.data = data;
	}
	
	public void	setData(T data)
	{
		this.data = data;
	}
	
	public T	getData()
	{
		return (data);
	}
}
