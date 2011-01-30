#ifndef _FONT_H
#define _FONT_H

#include "Engine2D.h"

namespace Engine2D {

	class Font : public Sprite {
	private:
		int widths[256];

	public:
		Font();
		virtual ~Font(void) { }

		void Print(int x, int y, std::string text, int color = 0xFFFFFFFF );

		int getCharWidth() { return this->width; }
		int getCharHeight() { return this->height; }
		void setCharWidth(int width) { this->width = width;	}
		void setCharSize(int width, int height) {
			setCharWidth( width );
			this->height = height;
		}

		bool loadWidthData(std::string filename);
		
	};

};

#endif