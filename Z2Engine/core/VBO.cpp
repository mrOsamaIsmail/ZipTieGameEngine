#include "VBO.h"

VBO::VBO(GLfloat* verticies, GLsizeiptr size,GLuint drawType)
{
	
	glGenBuffers(1, &ID);
	glBindBuffer(GL_ARRAY_BUFFER, ID);
	switch (drawType)
	{
	case GL_DYNAMIC_DRAW :
				
				glBufferData(GL_ARRAY_BUFFER, size, verticies, GL_DYNAMIC_DRAW);
				break;
	
	case GL_STATIC_DRAW :
				
				glBufferData(GL_ARRAY_BUFFER, size, verticies, GL_STATIC_DRAW);
				break;
	default:
				prnterror("VBO.CPP","no such a draw type exists");
				break;
	}
}

void VBO::Bind()
{
	glBindBuffer(GL_ARRAY_BUFFER, ID);
}

void VBO::UnBind()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VBO::Delete()
{
	glDeleteBuffers(GL_ARRAY_BUFFER, &ID);
}
