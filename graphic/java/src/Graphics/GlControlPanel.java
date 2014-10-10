package Graphics;

import org.lwjgl.opengl.GL11;

import Core.Window;
import Engine.ACamera;

public class GlControlPanel
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
		Window		window;
		int			width;
		int			height;
		
		window = Window.getCurrentWindow();
		if (window == null)
		{
			width = Window.DEFAULT_WIDTH;
			height = Window.DEFAULT_HEIGHT;
		}
		else
		{
			width = window.getWidth();
			height = window.getHeight();
		}
		
		/*
		GL11.glMatrixMode(GL11.GL_PROJECTION);
		GL11.glLoadIdentity();
		GL11.glOrtho(0, width, 0, height, 1, -1);
		GL11.glMatrixMode(GL11.GL_MODELVIEW);
		*/
		GL11.glViewport(0, 0, width, height);
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
	}
}
