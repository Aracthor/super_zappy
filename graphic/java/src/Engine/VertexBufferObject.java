package Engine;

import java.nio.FloatBuffer;

import org.lwjgl.BufferUtils;
import org.lwjgl.opengl.GL11;
import org.lwjgl.opengl.GL15;
import org.lwjgl.opengl.GL20;

public class VertexBufferObject implements IBindable
{
	private	int		id;
	private int		verticesNumber;
	private boolean	useColor;
	private boolean	useTexture;
	private int		colorIndex;
	private int		textureIndex;
	
	public	VertexBufferObject()
	{
		id = GL15.glGenBuffers();
		useColor = false;
		useTexture = false;
	}
	
	public void	bind()
	{
		GL15.glBindBuffer(GL15.GL_ARRAY_BUFFER, id);
	}

	public void	unbind()
	{
		GL15.glBindBuffer(GL15.GL_ARRAY_BUFFER, 0);
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
		
		this.bind();
		{
			GL15.glBufferData(GL15.GL_ARRAY_BUFFER, verticesBuffer, GL15.GL_STATIC_DRAW);
			GL20.glVertexAttribPointer(0, 3, GL11.GL_FLOAT, false, 0, 0);
			if (useColor)
			{
				GL20.glVertexAttribPointer(1, 3, GL11.GL_FLOAT, false, 0, colorIndex * 4);
			}
			if (useTexture)
			{
				GL20.glVertexAttribPointer(2, 3, GL11.GL_FLOAT, false, 0, textureIndex * 4);
			}
		}
		this.unbind();
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
		GL11.glDrawArrays(GL11.GL_TRIANGLES, 0, verticesNumber);
	}
}
