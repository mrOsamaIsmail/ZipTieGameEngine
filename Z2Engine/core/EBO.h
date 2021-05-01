#ifndef EBO_H
#define EBO_H

#include "../pch.h"

class EBO 
{
public:
	GLuint ID;
	EBO(GLuint* indicies, GLsizeiptr size, GLuint drawType);
	void Bind();
	void UnBind();
	void Delete();
};


#endif