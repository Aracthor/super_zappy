package Helpers;

public class MathsHelper
{
	private static MathsHelper	s_instance;
	
	public static MathsHelper	getInstance()
	{
		if (s_instance == null)
		{
			s_instance = new MathsHelper();
		}
		return (s_instance);
	}
	
	
	private final float	PI;
	
	private	MathsHelper()
	{
		PI = 3.14159265359f;
	}
	
	public float	toRadians(float angle)
	{
		return (angle * this.PI / 180.0f);
	}
	
	public float	toDegrees(float angle)
	{
		return (angle * 180.0f / this.PI);
	}
	
	public float	cos(float angle)
	{
		return ((float)Math.cos((double)this.toRadians(angle)));
	}
	
	public float	sin(float angle)
	{
		return ((float)Math.sin((double)this.toRadians(angle)));
	}
	
	public float	tan(float angle)
	{
		return ((float)Math.tan((double)this.toRadians(angle)));
	}
}
