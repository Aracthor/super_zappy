package Engine;

import java.io.IOException;
import java.nio.FloatBuffer;
import java.nio.file.Files;
import java.nio.file.Paths;

import org.lwjgl.BufferUtils;
import org.lwjgl.opengl.ARBFragmentShader;
import org.lwjgl.opengl.ARBShaderObjects;
import org.lwjgl.opengl.ARBVertexShader;
import org.lwjgl.opengl.GL11;
import org.lwjgl.util.vector.Matrix4f;
import org.lwjgl.util.vector.Vector2f;
import org.lwjgl.util.vector.Vector3f;

public class Shader implements IBindable
{
	private int			programId;
	private FloatBuffer	matrixBuffer;

	public	Shader(String vertexFile, String fragmentFile) throws GlException
	{
		int	vertexId;
		int	fragmentId;
		
		vertexId = this.createShaderId(vertexFile, ARBVertexShader.GL_VERTEX_SHADER_ARB);
		fragmentId = this.createShaderId(fragmentFile, ARBFragmentShader.GL_FRAGMENT_SHADER_ARB);
		programId = this.createProgramId(vertexId, fragmentId);
		matrixBuffer = BufferUtils.createFloatBuffer(4 * 4);
	}
	
	private	int	createShaderId(String file, int type) throws GlException
	{
		String	code;
		String	errorLog;
		int		id;
		
		id = ARBShaderObjects.glCreateShaderObjectARB(type);
		if (id == 0)
		{
			throw new GlException("Failed to create new shader object");
		}
		
		try
		{
			code = new String(Files.readAllBytes(Paths.get(file)));
		}
		catch (IOException exception)
		{
			throw new GlException("Problem parsing file " + file + " : " + exception.getMessage());
		}
		ARBShaderObjects.glShaderSourceARB(id, code);
		
		ARBShaderObjects.glCompileShaderARB(id);
		if (ARBShaderObjects.glGetObjectParameteriARB(id, ARBShaderObjects.GL_OBJECT_COMPILE_STATUS_ARB) == GL11.GL_FALSE)
		{
			errorLog = this.getErrorLog(id);
			throw new GlException("Cannot compile shader " + file + ", " + errorLog);
		}
		
		return (id);
	}
	
	private int	createProgramId(int vertexId, int fragmentId) throws GlException
	{
		int		id;
		String	errorLog;
		
		// Create new program
		id = ARBShaderObjects.glCreateProgramObjectARB();
		if (id == 0)
		{
			throw new GlException("Failed to create new program object");
		}
		
		// Attach to shaders
		ARBShaderObjects.glAttachObjectARB(id, vertexId);
		ARBShaderObjects.glAttachObjectARB(id, fragmentId);
		
		// Link program
		ARBShaderObjects.glLinkProgramARB(id);
		if (ARBShaderObjects.glGetObjectParameteriARB(id, ARBShaderObjects.GL_OBJECT_LINK_STATUS_ARB) == GL11.GL_FALSE)
		{
			errorLog = this.getErrorLog(id);
			throw new GlException("Cannot link shader program : " + errorLog);
		}
		
		// validate program
		ARBShaderObjects.glValidateProgramARB(id);
		if (ARBShaderObjects.glGetObjectParameteriARB(id, ARBShaderObjects.GL_OBJECT_VALIDATE_STATUS_ARB) == GL11.GL_FALSE)
		{
			errorLog = this.getErrorLog(id);
			throw new GlException("Cannot validate shader program : " + errorLog);
		}
		
		return (id);
	}
	
	private String	getErrorLog(int id)
	{
		return (ARBShaderObjects.glGetInfoLogARB(id, ARBShaderObjects.glGetObjectParameteriARB(id, ARBShaderObjects.GL_OBJECT_INFO_LOG_LENGTH_ARB)));
	}
	
	
	public void	bind()
	{
		ARBShaderObjects.glUseProgramObjectARB(programId);
	}
	
	public void	unbind()
	{
		ARBShaderObjects.glUseProgramObjectARB(0);
	}
	
	
	private int	getUniformLocation(String name) throws GlException
	{
		int	location;
		
		location = ARBShaderObjects.glGetUniformLocationARB(programId, name);
		if (location == -1)
		{
			throw new GlException("Error : uniform variable '" + name + "' doesn't exist.");
		}
		
		return (location);
	}
	
	public void	setUniform(String name, float value)
	{
		ARBShaderObjects.glUniform1fARB(this.getUniformLocation(name), value);
	}
	
	public void	setUniform(String name, Vector2f vector)
	{
		ARBShaderObjects.glUniform2fARB(this.getUniformLocation(name), vector.x, vector.y);
	}
	
	public void	setUniform(String name, Vector3f vector)
	{
		ARBShaderObjects.glUniform3fARB(this.getUniformLocation(name), vector.x, vector.y, vector.z);
	}
	
	public void	setUniform(String name, Matrix4f matrix)
	{
		matrix.store(matrixBuffer);
		matrixBuffer.flip();
		ARBShaderObjects.glUniformMatrix4ARB(this.getUniformLocation(name), false, matrixBuffer);
	}
}
