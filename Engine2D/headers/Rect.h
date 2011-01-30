#ifndef _RECT_H
#define _RECT_H

#include "Engine2D.h"

//***mod--floats to doubles

namespace Engine2D {

	class Rect {

	public:
		double left;
		double top;
		double right;
		double bottom;

	public:
        Rect();
		Rect(int left,int top,int right,int bottom);
		Rect(double left,double top,double right,double bottom);
		virtual ~Rect() { }

		double getLeft() { return left; }
		double getTop() { return top; }
		double getRight() { return right; }
		double getBottom() { return bottom; }
		
		double getWidth() { return right-left; }
		double getHeight() { return bottom-top; }

		bool isInside(Vector3 point);
		bool isInside(int x,int y);
		bool isInside(double x,double y);

	};


};

#endif