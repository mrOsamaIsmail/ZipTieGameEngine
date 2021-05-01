
#include "stbImageLayer.h"

unsigned char* STBImageLayer::LoadTexture(const char* FileName, int* width, int* height, int* comp)
{

	unsigned char* image = stbi_load(FileName, width, height, comp, STBI_rgb);

	if (image == nullptr)
		throw(std::string("Failed to load texture"));
	return image;
}
