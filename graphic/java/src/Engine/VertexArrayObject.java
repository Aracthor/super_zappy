package Engine;

import org.lwjgl.opengl.GL30;

public class VertexArrayObject implements IBindable
{
	private	int					id;
	private float[]				data;
	private int[]				elements;
	private VertexBufferObject	vbo;
	private int					colorIndex;
	private int					textureIndex;
	
	public VertexArrayObject()
	{
		id = GL30.glGenVertexArrays();
		elements = null;
	}
	
	public boolean	isEmpty()
	{
		return (vbo == null);
	}
	
	
	public void	bind()
	{
		GL30.glBindVertexArray(id);
	}

	public void	unbind()
	{
		GL30.glBindVertexArray(0);
	}
	
	
	public void	addVertices(float[] vertices)
	{
		data = vertices;
	}
	
	public void	addColors(float[] colors)
	{
		float[]	oldData = data;
		
		colorIndex = data.length;
		data = new float[oldData.length + colors.length];
		System.arraycopy(oldData, 0, data, 0, oldData.length);
		System.arraycopy(colors, 0, data, oldData.length, colors.length);
	}
	
	public void	addElements(int[] elements)
	{
		this.elements = elements;
	}
	
	public void	build()
	{
		boolean	useColor;
		boolean	useTexture;
		
		useColor = (colorIndex != 0);
		useTexture = (textureIndex != 0);
		
		this.bind();
		{
			vbo = new VertexBufferObject((elements != null));
			vbo.setData(data, useColor, useTexture, colorIndex, textureIndex);
			if (elements != null)
			{
				vbo.setElements(elements);
			}
		}
		this.unbind();
	}
	
	public void	draw()
	{
		this.bind();
		{
			vbo.draw();
		}
		this.unbind();
	}
}
