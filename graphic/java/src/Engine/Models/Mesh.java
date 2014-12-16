package Engine.Models;

import org.lwjgl.util.vector.Matrix4f;
import org.lwjgl.util.vector.Vector3f;

import Engine.GlControlPanel;
import Helpers.MathsHelper;

public class Mesh extends VertexArrayObject
{
	private Vector3f	translation;
	private Vector3f	rotation;
	private Vector3f	scale;
	private Matrix4f	modelMatrix;
	
	private final Vector3f	axisX;
	private final Vector3f	axisY;
	private final Vector3f	axisZ;
	
	private boolean		matrixIsToChange;
	
	public	Mesh()
	{
		super();
		translation = new Vector3f(0.0f, 0.0f, 0.0f);
		rotation = new Vector3f(0.0f, 0.0f, 0.0f);
		scale = new Vector3f(1.0f, 1.0f, 1.0f);
		modelMatrix = new Matrix4f();
		
		axisX = new Vector3f(1.0f, 0.0f, 0.0f);
		axisY = new Vector3f(0.0f, 1.0f, 0.0f);
		axisZ = new Vector3f(0.0f, 0.0f, 1.0f);
		
		matrixIsToChange = true;
	}
	
	public Mesh(Mesh copy)
	{
		super(copy);
		translation = new Vector3f(copy.translation);
		rotation = new Vector3f(copy.rotation);
		scale = new Vector3f(copy.scale);
		modelMatrix = new Matrix4f();
		
		axisX = new Vector3f(1.0f, 0.0f, 0.0f);
		axisY = new Vector3f(0.0f, 1.0f, 0.0f);
		axisZ = new Vector3f(0.0f, 0.0f, 1.0f);
		
		matrixIsToChange = true;
	}
	
	
	private void	createModelMatrix()
	{
		MathsHelper	mathsHelper = MathsHelper.getInstance();
		
		modelMatrix.setIdentity();
		modelMatrix.translate(translation);
		modelMatrix.rotate(mathsHelper.toRadians(rotation.z), axisZ);
		modelMatrix.rotate(mathsHelper.toRadians(rotation.y), axisY);
		modelMatrix.rotate(mathsHelper.toRadians(rotation.x), axisX);
		modelMatrix.scale(scale);
		
		matrixIsToChange = false;
	}
	
	public void	setPosition(float x, float y, float z)
	{
		translation.x = x;
		translation.y = y;
		translation.z = z;
		
		matrixIsToChange = true;
	}
	
	public void	setPosition(Vector3f position)
	{
		this.translation = position;
		
		matrixIsToChange = true;
	}
	
	public void	setRotation(float x, float y, float z)
	{
		rotation.x = x;
		rotation.y = y;
		rotation.z = z;
		
		matrixIsToChange = true;
	}
	
	public void	setRotation(Vector3f rotation)
	{
		this.rotation = rotation;
		
		matrixIsToChange = true;
	}
	
	public void	setScale(float x, float y, float z)
	{
		scale.x = x;
		scale.y = y;
		scale.z = z;
		
		matrixIsToChange = true;
	}
	
	public void	setScale(Vector3f scale)
	{
		this.scale = scale;
		
		matrixIsToChange = true;
	}
	
	public void	translate(float x, float y, float z)
	{
		translation.x += x;
		translation.y += y;
		translation.z += z;
		
		matrixIsToChange = true;
	}
	
	public void translate(Vector3f vector)
	{
		translation.x += vector.x;
		translation.y += vector.y;
		translation.z += vector.z;
		
		matrixIsToChange = true;
	}
	
	public void	rotate(float x, float y, float z)
	{
		rotation.x += x;
		rotation.y += y;
		rotation.z += z;
		
		matrixIsToChange = true;
	}
	
	public void	rotate(Vector3f vector)
	{
		rotation.x += vector.x;
		rotation.y += vector.y;
		rotation.z += vector.z;
		
		matrixIsToChange = true;
	}
	
	public void	scale(float x, float y, float z)
	{
		scale.x *= x;
		scale.y *= y;
		scale.z *= z;
		
		matrixIsToChange = true;
	}
	
	public void	scale(Vector3f vector)
	{
		scale.x *= vector.x;
		scale.y *= vector.y;
		scale.z *= vector.z;
		
		matrixIsToChange = true;
	}
	
	
	public Vector3f	getPosition()
	{
		return (translation);
	}
	
	public Vector3f	getRotation()
	{
		return (rotation);
	}
	
	public Vector3f	getScale()
	{
		return (scale);
	}
	
	
	@Override
	public void	draw()
	{
		if (matrixIsToChange)
		{
			this.createModelMatrix();
		}
		GlControlPanel.getInstance().getCurrentShader().setUniform("modelMatrix", modelMatrix);
		super.draw();
	}
}
