package Engine.Models;

import java.io.BufferedReader;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.Iterator;

import Exceptions.GlException;
import Exceptions.ParsingException;

public class	ObjParser
{
	private		ArrayList<Float>	vertices;
	private		ArrayList<Float>	colors;
	private		ArrayList<Integer>	indices;
	private		String				currentFileName;
	
	public		ObjParser()
	{
		vertices = new ArrayList<Float>();
		colors = new ArrayList<Float>();
		indices = new ArrayList<Integer>();
	}
	
	
	private void	reset(String fileName)
	{
		vertices.clear();
		colors.clear();
		indices.clear();
		currentFileName = fileName;
	}
	
	private void	parseVector3f(ArrayList<Float> data, String[] args)
	{
		if (args.length != 4)
		{
			throw new ParsingException("Failed to parse a vector3f in file " + currentFileName);
		}
		else
		{
			args[1] = args[1].replaceAll("--", "-");
			args[2] = args[2].replaceAll("--", "-");
			args[3] = args[3].replaceAll("--", "-");
			data.add(Float.parseFloat(args[1]));
			data.add(Float.parseFloat(args[2]));
			data.add(Float.parseFloat(args[3]));
		}
	}
	
	private void	parseVector3i(ArrayList<Integer> data, String[] args)
	{
		if (args.length != 4)
		{
			throw new ParsingException("Failed to parse a vector3i in file " + currentFileName);
		}
		else
		{
			data.add(Integer.parseInt(args[1]));
			data.add(Integer.parseInt(args[2]));
			data.add(Integer.parseInt(args[3]));
		}
	}
	
	private void	parseLine(String line)
	{
		String[]	args;
		
		args = line.split(" ");
		if (args[0].equals("v"))
		{
			this.parseVector3f(vertices, args);
		}
		else if (args[0].equals("vc"))
		{
			this.parseVector3f(colors, args);
		}
		else if (args[0].equals("f"))
		{
			this.parseVector3i(indices, args);
		}
	}
	
	private float[]		convertFloatArray(ArrayList<Float> arrayList)
	{
		Iterator<Float>	it;
		float[]			array;
		int				i;
		
		array = new float[arrayList.size()];
		i = 0;
		for (it = arrayList.iterator(); it.hasNext();)
		{
			array[i] = it.next();
			++i;
		}
		
		return (array);
	}
	
	private int[]			convertIntegerArray(ArrayList<Integer> arrayList)
	{
		Iterator<Integer>	it;
		int[]				array;
		int					i;
		
		array = new int[arrayList.size()];
		i = 0;
		for (it = arrayList.iterator(); it.hasNext();)
		{
			array[i] = it.next();
			++i;
		}
		
		return (array);
	}
	
	private Mesh	createMesh()
	{
		Mesh		mesh;
		float		vertices[] = this.convertFloatArray(this.vertices);
		float		colors[] = this.convertFloatArray(this.colors);
		int			indices[] = this.convertIntegerArray(this.indices);
		
		mesh = new Mesh();
		mesh.addVertices(vertices);
		mesh.addColors(colors);
		mesh.addIndices(indices);
		mesh.build();
		
		return (mesh);
	}
	
	public	Mesh		loadFile(String fileName)
	{
		FileReader		file;
		BufferedReader	reader;
		String			line;
		Mesh			mesh;
		
		this.reset(fileName);
		
		try
		{
			file = new FileReader(fileName);
			reader = new BufferedReader(file);
			while ((line = reader.readLine()) != null)
			{
				this.parseLine(line);
			}
			file.close();
			
			mesh = this.createMesh();
		}
		catch (Exception exception)
		{
			throw new GlException("Problem parsing file " + fileName + " : " + exception.getMessage());
		}
		
		return (mesh);
	}
}
