package Engine;

import org.lwjgl.util.vector.Matrix4f;
import org.lwjgl.util.vector.Vector3f;

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
	}
	
	private void	createModelMatrix()
	{
		MathsHelper	mathsHelper = MathsHelper.getInstance();
		
		modelMatrix.setIdentity();
		modelMatrix.scale(scale);
		modelMatrix.translate(translation);
		modelMatrix.rotate(mathsHelper.toRadians(rotation.x), axisX);
		modelMatrix.rotate(mathsHelper.toRadians(rotation.y), axisY);
		modelMatrix.rotate(mathsHelper.toRadians(rotation.z), axisZ);
	}
	
	public void	translate(Vector3f vector)
	{
		translation.x += vector.x * 0.001f;
		translation.y += vector.y * 0.001f;
		translation.z += vector.z * 0.001f;
	}
	
	public void	rotate(Vector3f vector)
	{
		rotation.x += vector.x;
		rotation.y += vector.y;
		rotation.z += vector.z;
	}
	
	public void	scale(Vector3f vector)
	{
		scale.x *= vector.x;
		scale.y *= vector.y;
		scale.z *= vector.z;
	}
	
	
	@Override
	public void	draw()
	{
		this.createModelMatrix();
		GlControlPanel.getInstance().getCurrentShader().setUniform("modelMatrix", modelMatrix);
		super.draw();
	}
}
