#ifndef _SHADER_CLASS_H
#define _SHADER_CLASS_H
#include "../pch.h"

std::string getFileContent(const char* FileName);

class Shader 
{
	public:
		GLuint ID;
		Shader(const char* vertexFile, const char* fragmentFile);
		void Activate();
		void Delete();
};



#endif // !_SHADER_CLASS_H
