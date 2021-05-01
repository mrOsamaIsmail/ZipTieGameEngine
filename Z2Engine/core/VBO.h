#ifndef  VBO_H
#define VBO_H

#include "../pch.h"

class VBO

{
	public:
		GLuint ID;
		VBO(GLfloat* verticies,GLsizeiptr size, GLuint drawType);
		void Bind();
		void UnBind();
		void Delete();


};


#endif // ! VBO_H
