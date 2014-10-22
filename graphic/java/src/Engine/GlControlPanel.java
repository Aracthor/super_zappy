package Engine;

import org.lwjgl.opengl.GL11;

import Engine.ACamera;

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
		this.depthMask = mask;
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
