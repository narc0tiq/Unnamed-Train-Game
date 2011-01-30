#ifndef _TEXTURE_H
#define _TEXTURE_H

#include "Engine2D.h"

class Texture
{
public:
	Texture();
	~Texture();
//	bool create(int width,int height);
	bool Load(std::string filename, D3DCOLOR transcolor = D3DCOLOR_XRGB(0,0,0));
	void Release();
	LPDIRECT3DTEXTURE9 GetTexture() { return texture; }
	int getWidth();
	int getHeight();

private:
	LPDIRECT3DTEXTURE9 texture;
    D3DXIMAGE_INFO info;
};

#endif
