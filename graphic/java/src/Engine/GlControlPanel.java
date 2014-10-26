package Engine;

import org.lwjgl.opengl.GL11;

import Engine.Camera.ACamera;

public class GlControlPanel extends ShaderControlPanel
{
	private static GlControlPanel	s_instance = null;
	
	public static GlControlPanel	getInstance()
	{
		if (s_instance == null)
		{
			s_instance = new GlControlPanel();
		}
		return (s_instance);
	}
	
	
	private	boolean	depthMask;
	
	
	private	GlControlPanel()
	{
		this.initGl();
		depthMask = false;
	}
	
	
	private	void	initGl()
	{
	}
	
	
	public void	setDepthMask(boolean mask)
	{
		if (mask == true)
		{
			GL11.glEnable(GL11.GL_DEPTH_TEST);
		}
		else
		{
			GL11.glDisable(GL11.GL_DEPTH_TEST);
		}
		this.depthMask = mask;
	}
	
	public void	setTexture2D(boolean texture2D)
	{
		if (texture2D == true)
		{
			GL11.glEnable(GL11.GL_TEXTURE_2D);
		}
		else
		{
			GL11.glDisable(GL11.GL_TEXTURE_2D);
		}
	}
	
	public void	setPolygonMode(int mode)
	{
		GL11.glPolygonMode(GL11.GL_FRONT_AND_BACK, mode);
	}
	
	public void	initFrame(ACamera camera)
	{
		int	clearMask;
		
		clearMask = GL11.GL_COLOR_BUFFER_BIT;
		if (depthMask == true)
		{
			clearMask |= GL11.GL_DEPTH_BUFFER_BIT;
		}
		
		GL11.glClear(clearMask);
		
		this.bindCurrentShader();
		camera.perspective();
		camera.lookAt();
	}

	public void	endFrame()
	{
		this.unbindCurrentShader();
	}

}
