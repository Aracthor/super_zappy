package Engine;

import java.util.HashMap;

import Debug.DebugLog;

public class ShaderControlPanel
{
	private Shader					currentShader;
	private HashMap<String, Shader>	shaders;
	
	public	ShaderControlPanel()
	{
		currentShader = null;
		shaders = new HashMap<String, Shader>();
	}
	
	protected void	bindCurrentShader()
	{
		if (currentShader != null)
		{
			currentShader.bind();
		}
		else
		{
			DebugLog.getInstance().err.print("Error : no selected Shader.");
		}
	}
	
	protected void	unbindCurrentShader()
	{
		if (currentShader != null)
		{
			currentShader.unbind();
		}
		else
		{
			DebugLog.getInstance().err.print("Error : no selected Shader.");
		}
	}
	
	
	public void		addShader(String name, String vertexFile, String fragmentFile)
	{
		shaders.put(name, new Shader(vertexFile, fragmentFile));
	}
	
	public void		addShader(String name, String fileName)
	{
		this.addShader(name, fileName + ".vert", fileName + ".frag");
	}
	
	public boolean	selectShader(String name)
	{
		boolean	selected;
		
		currentShader = shaders.get(name);
		selected = (currentShader != null);
		if (selected == false)
		{
			DebugLog.getInstance().err.print("ShaderControlPanel Error : Shader " + name + " doesn't exist.");
		}
		
		return (selected);
	}
	
	public Shader	getCurrentShader()
	{
		return (currentShader);
	}
}
