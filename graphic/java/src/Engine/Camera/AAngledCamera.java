package Engine.Camera;

import org.lwjgl.util.vector.Vector3f;

import Helpers.MathsHelper;

public class AAngledCamera extends ACamera
{
	protected float	angleX;
	protected float	angleY;
	
	public	AAngledCamera()
	{
		super();
	}
	
	public	AAngledCamera(float angle, float aspectRatio, float znear, float zfar)
	{
		super(angle, aspectRatio, znear, zfar);
	}
	
	
	private void	vectorsFromAngles()
	{
		MathsHelper	maths = MathsHelper.getInstance();
		Vector3f	forward = new Vector3f();
		
		forward.x = maths.cos(angleY) * maths.cos(angleX);
		forward.y = maths.cos(angleY) * maths.sin(angleX);
		forward.z = maths.sin(angleY);
		
		Vector3f.add(this.position, forward, this.target);
	}
	
	
	public void	setAngleX(float angleX)
	{
		this.angleX = angleX;
	}
	
	public void	setAngleY(float angleY)
	{
		this.angleY = angleY;
	}
	
	@Override
	public void	lookAt()
	{
		this.vectorsFromAngles();
		super.lookAt();
	}
}
