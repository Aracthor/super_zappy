package Engine.Models;

import org.lwjgl.opengl.GL30;
import org.lwjgl.util.vector.Vector3f;

import Engine.GlControlPanel;
import Engine.IBindable;

public class VertexArrayObject implements IBindable
{
	private	int					id;
	private float[]				data;
	private int[]				elements;
	private VertexBufferObject	vbo;
	private int					colorIndex;
	private int					textureIndex;
	private Vector3f			baseColor;
	
	public VertexArrayObject()
	{
		id = GL30.glGenVertexArrays();
		elements = null;
		baseColor = new Vector3f(1.0f, 1.0f, 1.0f);
	}
	
	public VertexArrayObject(VertexArrayObject copy)
	{
		id = copy.id;
		vbo = copy.vbo;
		baseColor = new Vector3f(copy.baseColor);
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
	
	public void	addTexCoords(float[] texCoords)
	{
		float[]	oldData = data;
		
		textureIndex = data.length;
		data = new float[oldData.length + texCoords.length];
		System.arraycopy(oldData, 0, data, 0, oldData.length);
		System.arraycopy(texCoords, 0, data, oldData.length, texCoords.length);
	}
	
	public void	addIndices(int[] elements)
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
	
	public void	setBaseColor(Vector3f color)
	{
		this.baseColor = color;
	}
	
	public void	draw()
	{
		GlControlPanel.getInstance().getCurrentShader().setUniform("base_color", baseColor);
		
		this.bind();
		{
			vbo.draw();
		}
		this.unbind();
	}
}
