package Engine;

import org.lwjgl.util.vector.Matrix4f;
import org.lwjgl.util.vector.Vector3f;

import Debug.DebugLog;
import Helpers.MathsHelper;


public abstract class ACamera
{
	private	float		angle;
	private	float		aspectRatio;
	private	float		znear;
	private	float		zfar;
	
	protected	Vector3f	position;
	protected	Vector3f	target;
	protected	Vector3f	up;
	private		Matrix4f	projectionMatrix;
	private		Matrix4f	viewMatrix;

	private Vector3f	axisX;
	private Vector3f	axisY;
	private Vector3f	axisZ;
	private Vector3f	axisDot;
	
	public	ACamera()
	{
		position = new Vector3f(0.0f, 0.0f, 0.0f);
		target = new Vector3f(0.0f, 0.0f, 0.0f);
		up = new Vector3f(0.0f, 0.0f, 1.0f);
		projectionMatrix = new Matrix4f();
		viewMatrix = new Matrix4f();
		
		axisX = new Vector3f();
		axisY = new Vector3f();
		axisZ = new Vector3f();
		axisDot = new Vector3f();
	}
	
	public	ACamera(float angle, float aspectRatio, float znear, float zfar)
	{
		this();
		this.angle = angle;
		this.aspectRatio = aspectRatio;
		this.znear = znear;
		this.zfar = zfar;
	}
	
	public	void	setPosition(Vector3f position)
	{
		this.position = position;
	}
	
	public	void	setTarget(Vector3f target)
	{
		this.target = target;
	}
	
	
	public	Vector3f	getPosition()
	{
		return (position);
	}
	
	public	Vector3f	getTarget()
	{
		return (target);
	}
	
	
	private void	createViewMatrix()
	{
		/*
		Vector3f.sub(target, position, axisZ);
		axisZ.normalise();
		Vector3f.cross(up, axisZ, axisX);
		axisX.normalise();
		Vector3f.cross(axisZ, axisX, axisY);
		
		axisDot.x = -Vector3f.dot(axisX, position);
		axisDot.y = -Vector3f.dot(axisY, position);
		axisDot.z = -Vector3f.dot(axisZ, position);
		
		viewMatrix.m00 = axisX.x;	viewMatrix.m01 = axisY.x;	viewMatrix.m02 = axisZ.x;	viewMatrix.m03 = 0.0f;
		viewMatrix.m10 = axisX.y;	viewMatrix.m11 = axisY.y;	viewMatrix.m12 = axisZ.y;	viewMatrix.m13 = 0.0f;
		viewMatrix.m20 = axisX.z;	viewMatrix.m21 = axisY.z;	viewMatrix.m22 = axisZ.z;	viewMatrix.m23 = 0.0f;
		viewMatrix.m30 = axisDot.x;	viewMatrix.m31 = axisDot.y;	viewMatrix.m32 = axisDot.z;	viewMatrix.m33 = 1.0f;
		*/
		viewMatrix.setIdentity();
		viewMatrix.translate(position);
	}
	
	public void	perspective()
	{
		MathsHelper	mathsHelper = MathsHelper.getInstance();
		
		float scaleY;
		float scaleX;
		float frustumLength;
		
		scaleY = 1.0f / (float)Math.tan(mathsHelper.toRadians(angle / 2.0f));
		scaleX = scaleY / aspectRatio;
		frustumLength = zfar - znear;
		
		projectionMatrix.setZero();
		projectionMatrix.m00 = scaleX;
		projectionMatrix.m11 = scaleY;
		projectionMatrix.m22 = -((zfar + znear) / frustumLength);
		projectionMatrix.m23 = -1.0f;
		projectionMatrix.m32 = -((2.0f * znear * zfar) / frustumLength);

		GlControlPanel.getInstance().getCurrentShader().setUniform("projectionMatrix", projectionMatrix);
	}
	
	public void	lookAt()
	{
		if (position.x == target.x && position.y == target.y && position.z == target.z)
		{
			DebugLog.getInstance().err.print("WARNING : Camera position and target are equals.");
			viewMatrix.setIdentity();
		}
		else
		{
			this.createViewMatrix();
		}
		
		GlControlPanel.getInstance().getCurrentShader().setUniform("viewMatrix", viewMatrix);
	}
}
