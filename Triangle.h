#ifndef TRIANGLE_H_
#define TRIANGLE_H_
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include <stdexcept>
#define SQR (1.73205080757) // square root of 3
#define SQR2 (1.41421) // square root of 2
#define PI (3.14159265) // the number of pi
using namespace std;
namespace Melih{
class Triangle : public Shape
{
	
	public:
		double perimeter()const;
		double area()const;
		//bool operator==(const Shape& shape)const;
		//bool operator!=(const Shape& shape)const;
		Triangle& operator++() ;
		Triangle& operator++(int ignoreMe) ;
		Triangle& operator--() ;
		Triangle& operator--(int ignoreMe) ;
		void draw(ostream& fp,string color)const;
		Triangle(double conSide)throw (std::invalid_argument);
		Triangle();
		Triangle(double conSide,double conLX,double conLY,double conMX,double conMY,double conRX,double conRY)throw (std::invalid_argument);
		inline double getLeftX()const noexcept;
		inline double getLeftY()const noexcept;
		inline double getMidX()const noexcept;    //getter functions
		inline double getMidY()const noexcept;
		inline double getRightX()const noexcept;
		inline double getRightY()const noexcept;
		double getSide()const noexcept;
		void setLeftX(double sLeftX);
		void setLeftY(double sLeftY);
		void setMidX(double sMidX); //setter functions
		void setMidY(double sMidY);
		void setRightX(double sRightX);
		void setRightY(double sRightY);
		void setSide(double sSide);
		Triangle& operator+(double num)const;
		Triangle& operator-(double num)const;
		bool operator<(const Triangle& shape)const ;
		bool operator>(const Triangle& shape)const ;
		bool operator<=(const Triangle& shape)const ;
		bool operator>=(const Triangle& shape)const ;
	private:
		double side;
		double leftX;
		double leftY;  // private members for corners coordinates and side input
		double midX;
		double midY;
		double rightX;
		double rightY;
	
	

};
}
#endif

