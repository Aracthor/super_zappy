package Core;

import org.lwjgl.opengl.ContextAttribs;
import org.lwjgl.opengl.Display;
import org.lwjgl.opengl.DisplayMode;
import org.lwjgl.opengl.PixelFormat;

import Exceptions.LaunchException;

public class	Window
{
	public final static int		DEFAULT_WIDTH = 800;
	public final static int		DEFAULT_HEIGHT = 600;
	public final static int		DEFAULT_BPP = org.lwjgl.opengl.Display.getDisplayMode().getBitsPerPixel();
	public final static int		DEFAULT_FPS = 60;
	public final static String	DEFAULT_TITLE = "Graphic client";
	
	private static	Window		s_currentWindow = null;
	
	public static Window		getCurrentWindow()
	{
		return (s_currentWindow);
	}
	
	public static void			setCurrentWindow(Window window)
	{
		s_currentWindow = window;
	}
	
	
	private int		width;
	private int		height;
	private int		bpp;
	private int		framerateLimit;
	private String	title;

	public 		Window()
	{
		this.width = Window.DEFAULT_WIDTH;
		this.height = Window.DEFAULT_HEIGHT;
		this.bpp = Window.DEFAULT_BPP;
		this.framerateLimit = Window.DEFAULT_FPS;
		this.title = Window.DEFAULT_TITLE;
		
		Window.setCurrentWindow(this);
	}
	
	public		Window(int width, int height)
	{
		this();
		this.width = width;
		this.height = height;
	}

	
	public int	getWidth()
	{
		return this.width;
	}

	public int	getHeight()
	{
		return this.height;
	}

	public int	getBPP()
	{
		return this.bpp;
	}

	public int	getFramerateLimit()
	{
		return this.framerateLimit;
	}

	
	public void	open() throws LaunchException
	{
		System.out.println("Creating window...");
		PixelFormat pixelFormat = new PixelFormat();
		ContextAttribs contextAttributes = new ContextAttribs(4, 3)
		.withForwardCompatible(true)
		.withProfileCore(true);
		
		try
		{
			this.setDisplayMode();
			Display.create(pixelFormat, contextAttributes);
		}
		catch (Exception exception)
		{
			throw (new LaunchException("Cannot create window : " + exception.toString()));
		}
		System.out.println("Window created !");
	}
	
	private void	setDisplayMode() throws Exception
	{
		Display.setDisplayMode(new DisplayMode(this.width, this.height));
		DisplayMode[]	dm = org.lwjgl.util.Display.getAvailableDisplayModes(this.width, this.height, -1, -1, -1, -1, 60, 60);
		String[]		args = new String[]
			{
				"width=" + this.width,
				"height=" + this.height,
				"freq=" + this.framerateLimit,
				"bpp=" + this.bpp
			};
		org.lwjgl.util.Display.setDisplayMode(dm, args);
		Display.setTitle(this.title);
	}
	
	
	
	public void	display()
	{
		Display.sync(this.framerateLimit);
		Display.update();
	}
}
