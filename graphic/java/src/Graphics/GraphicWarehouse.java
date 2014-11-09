package Graphics;

import java.util.HashMap;

import Engine.Texture;
import Engine.Models.Mesh;
import Engine.Models.ObjParser;

public class		GraphicWarehouse
{
	private static	GraphicWarehouse	s_instance;
	
	public static synchronized void createWarehouse()
	{
		s_instance = new GraphicWarehouse();
	}
	
	public static synchronized GraphicWarehouse	getInstance()
	{
		return (s_instance);
	}
	
	
	private HashMap<String, Texture>	textures;
	private HashMap<String, Mesh>		models;
	private HashMap<String, Mesh>		textureSquares;
	
	private		GraphicWarehouse()
	{
		textures = new HashMap<String, Texture>();
		models = new HashMap<String, Mesh>();
		textureSquares = new HashMap<String, Mesh>();
		
		this.createTextures();
		this.createModels();
		this.createTextureSquares();
	}
	
	private void	createTextures()
	{
		this.addTexture("objects");
	}
	
	private void	createModels()
	{
		ObjParser	parser = new ObjParser();
		
		this.addModel("cube", parser);
		this.addModel("bush", parser);
		this.addModel("shrub", parser);
		this.addModel("ash", parser);
		this.addModel("oak", parser);
		this.addModel("saplin", parser);
		this.addModel("maple", parser);
		this.addModel("pawn", parser);
	}
	
	private void	createTextureSquares()
	{
		float		vertices[] = {
				0.0f, 0.0f, 1.0f,
				0.0f, 1.0f, 1.0f,
				0.0f, 1.0f, 0.0f,
				0.0f, 0.0f, 0.0f
				};
		float		texCoords[] = new float[2 * 4];
		int			indices[] = {
				0, 1, 2, 0, 3, 2
				};
		
		this.addTextureSquare("bush",	vertices, texCoords, indices, 0.0f, 0.1f, 0.0f, 1.0f);
		this.addTextureSquare("shrub",	vertices, texCoords, indices, 0.1f, 0.2f, 0.0f, 1.0f);
		this.addTextureSquare("ash",	vertices, texCoords, indices, 0.2f, 0.3f, 0.0f, 1.0f);
		this.addTextureSquare("oak",	vertices, texCoords, indices, 0.3f, 0.4f, 0.0f, 1.0f);
		this.addTextureSquare("saplin",	vertices, texCoords, indices, 0.4f, 0.5f, 0.0f, 1.0f);
		this.addTextureSquare("maple",	vertices, texCoords, indices, 0.5f, 0.6f, 0.0f, 1.0f);
	}
	
	private void	addTexture(String name)
	{
		Texture		texture;
		
		texture = new Texture("ressources/textures/" + name + ".png");
		textures.put(name, texture);
	}
	
	private void	addModel(String name, ObjParser parser)
	{
		String		fileName;
		
		fileName = "ressources/models/" + name + ".obj";
		
		models.put(name, parser.loadFile(fileName));
	}
	
	private void	addTextureSquare(String name, float vertices[], float texCoords[], int indices[],
									 float beginX, float endX, float beginY, float endY)
	{
		Mesh		mesh;
		
		texCoords[0] = beginX;	texCoords[1] = beginY;
		texCoords[2] = endX;	texCoords[3] = beginY;
		texCoords[4] = endX;	texCoords[5] = endY;
		texCoords[6] = beginX;	texCoords[7] = endY;
		
		mesh = new Mesh();
		mesh.addVertices(vertices);
		mesh.addTexCoords(texCoords);
		mesh.addIndices(indices);
		mesh.build();
		textureSquares.put(name, mesh);
	}
	
	
	public Texture	getTexture(String name)
	{
		return (textures.get(name));
	}
	
	public Mesh		getTextureSquare(String name)
	{
		return (textureSquares.get(name));
	}
	
	public Mesh		getModel(String name)
	{
		return (models.get(name));
	}
}
