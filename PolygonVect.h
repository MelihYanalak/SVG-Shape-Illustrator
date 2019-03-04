#ifndef POLYGONVECT_H_
#define POLYGONVECT_H_
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
class PolygonVect : public Polygon{

	public:
		double area()const;
		double perimeter()const;
		void draw(ostream& fp,string color)const;
		PolygonVect(Circle& c1);
		PolygonVect(Rectangle& r1);
		PolygonVect(Triangle& t1);
		virtual PolygonVect& operator++();
		virtual PolygonVect& operator++(int ignoreMe);
		virtual PolygonVect& operator--();
		virtual PolygonVect& operator--(int ignoreMe);
		void setPointX(double input,int index);
		vector<double> getPointX();
		void setPointY(double input,int index);
		vector<double> getPointY();
	private:
		vector<double> pointX;
		vector<double> pointY;	
		double vArea;
		double vPerimeter;
	
};
}
#endif
