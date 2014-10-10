package Graphics;

import java.util.ArrayList;

import org.lwjgl.opengl.GL30;

public class VertexArrayObject
{
	private	int	id;
	private ArrayList<VertexBufferObject>	vbos;
	
	public VertexArrayObject()
	{
		id = GL30.glGenVertexArrays();
		vbos = new ArrayList<VertexBufferObject>();
	}
	
	
	private void	bind()
	{
		GL30.glBindVertexArray(id);
	}

	private void	unbind()
	{
		GL30.glBindVertexArray(0);
	}
	
	
	public void	addMesh(float[] vertices)
	{
		VertexBufferObject	vbo;
		
		this.bind();
		{
			vbo = new VertexBufferObject();
			vbo.setData(vertices);
			vbos.add(vbo);
		}
		this.unbind();
	}
	
	public void	draw()
	{
		this.bind();
		{
			for (VertexBufferObject vbo : vbos)
			{
				vbo.draw();
			}
		}
		this.unbind();
	}
}
