#include "ShaderClass.h"

Shader::Shader(const char* vertexFile, const char* fragmentFile)
{
	std::string vertex = getFileContent(vertexFile);
	std::string fragment = getFileContent(fragmentFile);

	const char* vertex_src = vertex.c_str();
	const char* fragment_src = fragment.c_str();

	GLuint vert = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vert, 1, &vertex_src, NULL);
	glCompileShader(vert);

	GLuint frag = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(frag, 1, &fragment_src, NULL);
	glCompileShader(frag);

	ID = glCreateProgram();
	glAttachShader(ID, vert);
	glAttachShader(ID, frag);

	glLinkProgram(ID);
}

void Shader::Activate()
{
	glUseProgram(ID);
}

void Shader::Delete()
{
	glDeleteProgram(ID);
}

std::string getFileContent(const char* FileName)
{
	std::ifstream in(FileName, std::ios::binary);
	if (in)
	{
		std::string contents;
		in.seekg(0, std::ios::end);
		contents.resize(in.tellg());
		in.seekg(0, std::ios::beg);
		in.read(&contents[0], contents.size());
		in.close();
		return(contents);
	}
	//no file found
	throw(errno);
}
