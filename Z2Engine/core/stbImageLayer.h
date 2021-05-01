#ifndef stbimagelayer_h
#define stbimagelayer_h

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include "../pch.h"

class STBImageLayer
{
public:
	static unsigned char* LoadTexture(const char* FileName, int* width, int* height, int* comp);
	

};



#endif