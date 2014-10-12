package Data;

import Debug.DebugLog;

public enum EItem
{
	None(0);
	
	private int	id;
	
	private EItem(int id)
	{
		this.id = id;
	}
	
	
	public static EItem	getFromId(int id)
	{
		EItem	found;
		
		found = null;
		for (EItem Item : EItem.values())
		{
			if (Item.id == id)
			{
				found = Item;
			}
		}
		
		if (found == null)
		{
			DebugLog.getInstance().err.print("Item error : No Item found for Id " + id + ".");
		}
		
		return (found);
	}
}
