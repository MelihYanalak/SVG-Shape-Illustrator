#ifndef RECTANGLE_H_
#define RECTANGLE_H_
#include <iostream>
#include <fstream>
#include <vector>
#include "Shape.h"
#include "Circle.h"
#include "Triangle.h"
using namespace std;
namespace Melih{

class Rectangle : public Shape
{
	public:
	double perimeter()const;
	double area()const;
	Rectangle& operator++();
	Rectangle& operator--(int ignoreMe);
	Rectangle& operator--();
	Rectangle& operator++(int ignoreMe);
	//bool operator==(const Shape& shape)const;
	//bool operator!=(const Shape& shape)const;
	Rectangle(double conWidth,double conLength)throw (std::invalid_argument); // constructors
	Rectangle()noexcept;
	Rectangle(double conWidth,double conLength,double conRDX,double conRDY)throw (std::invalid_argument);
	void draw(ostream& fp,string color)const;
	double getWidth()const;
	double getLength()const;
	inline double getRiDownX()const;    //getter functions
	inline double getRiDownY()const;
	void setWidth(double sWidth);
	void setLength(double sLength);
	void setRiDownX(double sRiDownX);   // setter functions
	void setRiDownY(double sRiDownY);
	Rectangle& operator+(double num)const;
	Rectangle& operator-(double num)const;
	bool operator<(const Rectangle& shape)const;
	bool operator>(const Rectangle& shape)const;
	bool operator<=(const Rectangle& shape)const;
	bool operator>=(const Rectangle& shape)const;
	private:
	double width;
	double length;
	double riDownX;   // private members width,length and right down corners coordinates
	double riDownY;
	
};
}
#endif


