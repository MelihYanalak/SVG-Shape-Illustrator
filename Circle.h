#ifndef CIRCLE_H_   
#define CIRCLE_H_
#include <iostream>
#include <fstream>
#include "Triangle.h"
#include "Rectangle.h"
#include <string>
#include "Shape.h"
using namespace std;
namespace Melih{

class Circle : public Shape
{
	public:
		
		virtual Circle& operator++();
		virtual Circle& operator++(int ignoreMe);
		virtual Circle& operator--();
		virtual Circle& operator--(int ignoreMe);
		//virtual bool operator==(const Shape& shape)const;
		//virtual bool operator!=(const Shape& shape)const;
		virtual double perimeter()const;
		virtual double area()const;
		Circle operator+(double num)const;
		Circle operator-(double num)const;
		bool operator<(const Circle& shape)const;
		bool operator>(const Circle& shape)const;
		bool operator<=(const Circle& shape)const;
		bool operator>=(const Circle& shape)const;
		void draw(ostream& fp,string color)const;  // draw member function
		Circle();  // no parameter constructor
		Circle(double conRadius)throw(std::invalid_argument); // constructor with radius parameter
		Circle(double conRadius,double conOrX,double conOrY)throw(std::invalid_argument);
		double getRadius()const; // getter function for radius
		inline double getOriginX()const; // getter function for origin
		inline double getOriginY()const;
		void setRadius(double sRadius); // setter function for radius
		void setOriginX(double sOriginX); // setter function for originX
		void setOriginY(double sOriginY);  // setter function for originY
	private:
		double radius;	 // radius member private
		double originX; // originX member is the center coordinate in x direction
		double originY;  // originY member is the center coordinate in y direction
		
	
};
}
#endif



