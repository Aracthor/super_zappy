package Data;

import Debug.DebugLog;

public enum EObject
{
	None(0);
	
	private int	id;
	
	private EObject(int id)
	{
		this.id = id;
	}
	
	
	public static EObject	getFromId(int id)
	{
		EObject	found;
		
		found = null;
		for (EObject Object : EObject.values())
		{
			if (Object.id == id)
			{
				found = Object;
			}
		}
		
		if (found == null)
		{
			DebugLog.getInstance().err.print("Object error : No Object found for Id " + id + ".");
		}
		
		return (found);
	}
}
