#include "EBO.h"

EBO::EBO(GLuint* indicies, GLsizeiptr size, GLuint drawType)
{
	glGenBuffers(1, &ID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
	switch (drawType)
	{
	case GL_DYNAMIC_DRAW:

		glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indicies, GL_DYNAMIC_DRAW);
		break;

	case GL_STATIC_DRAW:

		glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indicies, GL_STATIC_DRAW);
		break;
	default:
		prnterror("EBO.CPP", "no such a draw type exists");
		break;
	}
}

void EBO::Bind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
}

void EBO::UnBind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void EBO::Delete()
{
	glDeleteBuffers(GL_ELEMENT_ARRAY_BUFFER, &ID);
}
