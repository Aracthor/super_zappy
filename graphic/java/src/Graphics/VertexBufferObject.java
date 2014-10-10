package Graphics;

import java.nio.FloatBuffer;

import org.lwjgl.BufferUtils;
import org.lwjgl.opengl.GL11;
import org.lwjgl.opengl.GL15;
import org.lwjgl.opengl.GL20;

public class VertexBufferObject
{
	private	int	id;
	private int	verticesNumber;
	
	public	VertexBufferObject()
	{
		id = GL15.glGenBuffers();
	}
	
	private void	bind()
	{
		GL15.glBindBuffer(GL15.GL_ARRAY_BUFFER, id);
	}

	private void	unbind()
	{
		GL15.glBindBuffer(GL15.GL_ARRAY_BUFFER, 0);
	}
	
	
	public void	setData(float[] vertices)
	{
		FloatBuffer	verticesBuffer;
		
		verticesNumber = vertices.length / 3;
		
		verticesBuffer = BufferUtils.createFloatBuffer(vertices.length);
		verticesBuffer.put(vertices);
		verticesBuffer.flip();
		
		this.bind();
		{
			GL15.glBufferData(GL15.GL_ARRAY_BUFFER, verticesBuffer, GL15.GL_STATIC_DRAW);
			GL20.glVertexAttribPointer(0, 3, GL11.GL_FLOAT, false, 0, 0);
		}
		this.unbind();
	}
	
	public void	draw()
	{
		GL20.glEnableVertexAttribArray(0);
		GL11.glDrawArrays(GL11.GL_TRIANGLES, 0, verticesNumber);
	}
}
