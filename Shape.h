#ifndef SHAPE_H_
#define SHAPE_H_
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
namespace Melih{

class Shape{

	public:
		virtual ~Shape()=default;
		virtual double area()const = 0;
		virtual double perimeter()const = 0;
		virtual Shape& operator++() = 0;
		virtual Shape& operator++(int ignoreMe) = 0;
		virtual Shape& operator--() = 0;
		virtual Shape& operator--(int ignoreMe) = 0;
		virtual bool operator==(const Shape& other)const;
		virtual bool operator!=(const Shape& other)const;
		virtual void draw(ostream& fp,string color)const = 0;
};
}
#endif

