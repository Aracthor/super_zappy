package Engine.Models;

import java.nio.FloatBuffer;
import java.nio.IntBuffer;

import org.lwjgl.BufferUtils;
import org.lwjgl.opengl.GL11;
import org.lwjgl.opengl.GL15;
import org.lwjgl.opengl.GL20;

import Engine.GlControlPanel;
import Engine.IBindable;

public class VertexBufferObject implements IBindable
{
	private	int			arrayId;
	private	int			elementsId;
	private int			verticesNumber;
	private int			elementsNumber;
	private boolean		useElements;
	private boolean		useColor;
	private boolean		useTexture;
	
	public	VertexBufferObject(boolean elements)
	{
		arrayId = GL15.glGenBuffers();
		useElements = elements;
		if (useElements)
		{
			elementsId = GL15.glGenBuffers();
		}
		useColor = false;
		useTexture = false;
	}
	
	public void	bind()
	{
		GL15.glBindBuffer(GL15.GL_ARRAY_BUFFER, arrayId);
		if (useElements)
		{
			GL15.glBindBuffer(GL15.GL_ELEMENT_ARRAY_BUFFER, elementsId);
		}
	}

	public void	unbind()
	{
		GL15.glBindBuffer(GL15.GL_ARRAY_BUFFER, 0);
		if (useElements)
		{
			GL15.glBindBuffer(GL15.GL_ELEMENT_ARRAY_BUFFER, 0);
		}
	}
	
	
	public void	setData(float[] vertices, boolean useColor, boolean useTexture, int colorIndex, int textureIndex)
	{
		FloatBuffer	verticesBuffer;
		
		this.useColor = useColor;
		this.useTexture = useTexture;
		
		verticesNumber = vertices.length / 3;
		
		verticesBuffer = BufferUtils.createFloatBuffer(vertices.length);
		verticesBuffer.put(vertices);
		verticesBuffer.flip();
		
		GL15.glBindBuffer(GL15.GL_ARRAY_BUFFER, arrayId);
		{
			GL15.glBufferData(GL15.GL_ARRAY_BUFFER, verticesBuffer, GL15.GL_STATIC_DRAW);
			GL20.glVertexAttribPointer(0, 3, GL11.GL_FLOAT, false, 0, 0);
			if (useColor)
			{
				GL20.glVertexAttribPointer(1, 3, GL11.GL_FLOAT, false, 0, colorIndex * 4);
			}
			if (useTexture)
			{
				GL20.glVertexAttribPointer(2, 2, GL11.GL_FLOAT, false, 0, textureIndex * 4);
			}
		}
		GL15.glBindBuffer(GL15.GL_ARRAY_BUFFER, 0);
	}
	
	public void	setElements(int[] elements)
	{
		IntBuffer	elementsBuffer;

		elementsNumber = elements.length;
		elementsBuffer = BufferUtils.createIntBuffer(elementsNumber);
		elementsBuffer.put(elements);
		elementsBuffer.flip();

		GL15.glBindBuffer(GL15.GL_ELEMENT_ARRAY_BUFFER, elementsId);
		{
			GL15.glBufferData(GL15.GL_ELEMENT_ARRAY_BUFFER, elementsBuffer, GL15.GL_STATIC_DRAW);
		}
		GL15.glBindBuffer(GL15.GL_ELEMENT_ARRAY_BUFFER, 0);
	}
	
	public void	draw()
	{
		GlControlPanel.getInstance().getCurrentShader().setUniform("use_color", useColor);
		GlControlPanel.getInstance().getCurrentShader().setUniform("use_texture", useTexture);
		
		GL20.glEnableVertexAttribArray(0);
		if (useColor)
		{
			GL20.glEnableVertexAttribArray(1);
		}
		if (useTexture)
		{
			GL20.glEnableVertexAttribArray(2);
		}
		
		if (useElements)
		{
			GL15.glBindBuffer(GL15.GL_ELEMENT_ARRAY_BUFFER, elementsId);
			{
				GL11.glDrawElements(GL11.GL_TRIANGLES, elementsNumber, GL11.GL_UNSIGNED_INT, 0);
			}
			GL15.glBindBuffer(GL15.GL_ELEMENT_ARRAY_BUFFER, 0);
		}
		else
		{
			GL11.glDrawArrays(GL11.GL_TRIANGLES, 0, verticesNumber);
		}
	}
}
