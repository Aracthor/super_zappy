package Data;

import Exceptions.HooplaException;

public class Hoopla
{
	private EGround	ground;
	private int		height;
	private EItem	item;
	private int		itemNumber;
	private EObject	object;
	
	public	Hoopla(int ground_id, int height, int item_id, int itemNumber, int object_id)
	{
		this.ground = EGround.getFromId(ground_id);
		this.height = height > 0 ? height : 0;
		this.item = EItem.getFromId(item_id);
		this.itemNumber = itemNumber;
		this.object = EObject.getFromId(object_id);
		
		if (this.ground == null || this.item == null || this.object == null)
		{
			throw HooplaException.create(this);
		}
	}
	
	public EGround	getGroundType()
	{
		return (ground);
	}
	
	public int		getHeight()
	{
		return (height);
	}
	
	public EItem	getItemType()
	{
		return (item);
	}
	
	public int		getItemsNumber()
	{
		return (itemNumber);
	}
	
	public EObject	getObjectType()
	{
		return (object);
	}
}
