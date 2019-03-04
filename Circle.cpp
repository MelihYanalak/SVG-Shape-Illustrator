#include "Circle.h"  // include the header of circle
#include <iostream>
#include <fstream>
#include <vector>
#define PI (3.14)
using namespace std;
namespace Melih{
	void Circle::draw(ostream& fp,string color)const{

		fp<<"<circle cx=\""<<getOriginX()<<"\" cy=\""<<getOriginY()<<"\" r=\""<<getRadius()<<"\" stroke=\"black\" stroke-width=\"1\" fill=\""<<color<<"\" />"<<endl;

	}

	Circle::Circle(){    // No Parameter Constructor
	}
	Circle::Circle(double conRadius)throw (std::invalid_argument){   // Constructor with radius parameter
		if(conRadius <=0){
			throw invalid_argument("");
		}		
		setRadius(conRadius);
		setOriginX(conRadius);
		setOriginY(conRadius);
	}
	Circle::Circle(double conRadius,double conOrX,double conOrY)throw(std::invalid_argument){
		if(conRadius <=0){
			throw invalid_argument("");
		}
		setRadius(conRadius);
		setOriginX(conOrX);
		setOriginY(conOrY);


	}
	double Circle::getRadius()const{   // getter function for radius
		return radius;

	}
	inline double Circle::getOriginX()const{ // getter function for originX
		return originX;

	}
	inline double Circle::getOriginY()const{ // getter function for originY
		return originY;

	}
	void Circle::setRadius(double sRadius){  // setter function for radius
		radius = sRadius;

	}
	void Circle::setOriginX(double sOriginX){ // setter function for originX
		originX = sOriginX;

	}
	void Circle::setOriginY(double sOriginY){   // setter function for originY
		originY = sOriginY;                 

	}
	Circle& Circle::operator++(){
		setOriginX(getOriginX()+1.0);
		setOriginY(getOriginY()+1.0);
		return *this;
		

	}
	Circle& Circle::operator++(int ignoreMe){
		double tempX,tempY;
		tempX = getOriginX();
		tempY = getOriginY();
		Circle newCirc(getRadius(),tempX,tempY);
		setOriginX(getOriginX()+1.0);
		setOriginY(getOriginY()+1.0);	
		return newCirc;

	}
	Circle& Circle::operator--(){
		setOriginX(getOriginX()-1.0);
		setOriginY(getOriginY()-1.0);
		return *this;

	}
	Circle& Circle::operator--(int ignoreMe){
		double tempX,tempY;
		tempX = getOriginX();
		tempY = getOriginY();
		Circle newCirc(getRadius(),tempX,tempY);
		setOriginX(getOriginX()-1.0);
		setOriginY(getOriginY()-1.0);	
		return newCirc;


	}

	Circle Circle::operator+(double num)const{
		Circle newCirc(getRadius()+num,getOriginX(),getOriginY());
		return newCirc;

	}
	Circle Circle::operator-(double num)const{
		Circle newCirc(getRadius()-num,getOriginX(),getOriginY());
		return newCirc;


	}
	double Circle::perimeter()const{
		return (2*PI*getRadius());

	}
	double Circle::area()const{
		return (PI*getRadius()*getRadius());

	}
	/*
	bool Circle::operator==(const Shape& shape)const{		
		if(area()==shape.area()){
			return 1;
		}
		else{
			return 0;
		}

	}
	bool Circle::operator!=(const Shape& shape)const{
		if(area()==shape.area()){
			return 0;
		}
		else{
			return 1;
		}


	}*/
	bool Circle::operator<(const Circle& shape)const{
		if(area()<shape.area()){
			return 1;
		}
		else{
			return 0;
		}
	}
	bool Circle::operator>(const Circle& shape)const{
		if(area()>shape.area()){
			return 1;
		}
		else{
			return 0;
		}
	}
	bool Circle::operator<=(const Circle& shape)const{
		if(area()<= shape.area()){
			return 1;
		}
		else{
			return 0;
		}
	}
	bool Circle::operator>=(const Circle& shape)const{
		if(area()>= shape.area()){
			return 1;
		}
		else{
			return 0;
		}

	}

	


}
