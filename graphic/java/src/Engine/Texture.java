package Engine;

import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.nio.ByteBuffer;

import org.lwjgl.opengl.GL11;
import org.lwjgl.opengl.GL13;
import org.lwjgl.opengl.GL30;
import org.lwjgl.util.glu.GLU;

import Exceptions.GlException;
import Exceptions.ParsingException;
import de.matthiasmann.twl.utils.PNGDecoder;
import de.matthiasmann.twl.utils.PNGDecoder.Format;

public class	Texture implements IBindable
{
	private int	id;
	
	public		Texture(String fileName)
	{
		id = GL11.glGenTextures();
		GL13.glActiveTexture(GL13.GL_TEXTURE0);
		this.bind();
		{
			this.parseFile(fileName);
		}
		this.unbind();
	}
	
	private void	parseFile(String fileName)
	{
		ByteBuffer	buf;
		int			width, height;
		
		try
		{
			InputStream stream = new FileInputStream(fileName);
			PNGDecoder decoder = new PNGDecoder(stream);
			
			width = decoder.getWidth();
			height = decoder.getHeight();
			
			buf = ByteBuffer.allocateDirect(4 * width * height);
			decoder.decode(buf, width * 4, Format.RGBA);
			buf.flip();
			
			stream.close();
		}
		catch (IOException exception)
		{
			throw new ParsingException(exception.getMessage());
		}
		
		// All RGB bytes are aligned to each other and each component is 1 byte
		GL11.glPixelStorei(GL11.GL_UNPACK_ALIGNMENT, 1);
		
		// Upload the texture data and generate mip maps (for scaling)
		GL11.glTexImage2D(GL11.GL_TEXTURE_2D, 0, GL11.GL_RGB, width, height, 0, GL11.GL_RGBA, GL11.GL_UNSIGNED_BYTE, buf);
		GL30.glGenerateMipmap(GL11.GL_TEXTURE_2D);
		
		// Setup the ST coordinate system
		GL11.glTexParameteri(GL11.GL_TEXTURE_2D, GL11.GL_TEXTURE_WRAP_S, GL11.GL_REPEAT);
		GL11.glTexParameteri(GL11.GL_TEXTURE_2D, GL11.GL_TEXTURE_WRAP_T, GL11.GL_REPEAT);
		
		// Setup what to do when the texture has to be scaled
		GL11.glTexParameteri(GL11.GL_TEXTURE_2D, GL11.GL_TEXTURE_MAG_FILTER, GL11.GL_NEAREST);
		GL11.glTexParameteri(GL11.GL_TEXTURE_2D, GL11.GL_TEXTURE_MIN_FILTER, GL11.GL_LINEAR_MIPMAP_LINEAR);
		
		// Check Error
		int error = GL11.glGetError();
		if (error != GL11.GL_NO_ERROR)
		{
			throw new GlException("Error loading texture " + fileName + " : " + GLU.gluErrorString(error));
		}
	}

	@Override
	public void bind()
	{
		GL11.glBindTexture(GL11.GL_TEXTURE_2D, id);
	}

	@Override
	public void unbind()
	{
		GL11.glBindTexture(GL11.GL_TEXTURE_2D, 0);
	}
}
