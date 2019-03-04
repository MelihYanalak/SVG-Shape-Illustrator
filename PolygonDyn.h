#ifndef POLYGONDYN_H_
#define POLYGONDYN_H_
#include "Shape.h"
#include "Polygon.h"
#include "Circle.h"
#include "Triangle.h"
#include "Rectangle.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
using namespace Melih;
namespace Melih{
class PolygonDyn : public Polygon{

	public:
		double area()const;
		double perimeter()const;
		void draw(ostream& fp,string color)const;
		PolygonDyn(Circle& c1);
		PolygonDyn(Rectangle& r1);
		PolygonDyn(Triangle& t1);
		virtual PolygonDyn& operator++();
		virtual PolygonDyn& operator++(int ignoreMe);
		virtual PolygonDyn& operator--();
		virtual PolygonDyn& operator--(int ignoreMe);
		void setPointX(double input,int index);
		double* getPointX();
		void setPointY(double input,int index);
		double* getPointY();
		int getSize();
	private:
		double vArea;
		double vPerimeter;
		double* pointX;
		double* pointY;
		int size;		
};
}
#endif
