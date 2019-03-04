#include "Rectangle.h"
#include <iostream>
#include <fstream>
#include <vector>	
using namespace std;
namespace Melih{
	// draw member function 
	void Rectangle::draw(ostream& fp,string color)const{
	fp<<"<rect x=\""<<getRiDownX()-(getWidth())<<"\" y=\""<<getRiDownY()-(getLength())<<"\" width=\""<<getWidth()<<"\" height=\""<<getLength()<<"\""<<endl<<"style=\"fill:"<<color<<";stroke:black;stroke-width:1;fill-opacity:1;stroke-opacity:0.9\" />"<<endl; 
		
}	
	Rectangle::Rectangle(double conWidth,double conLength)throw (std::invalid_argument){
		if(conWidth <= 0 || conLength <= 0){
			throw invalid_argument("");
		}
		setWidth(conWidth);    // constructor with parameter
		setLength(conLength);
		setRiDownX(conWidth);
		setRiDownY(conLength);
	}
	Rectangle::Rectangle(double conWidth,double conLength,double conRDX,double conRDY)throw (std::invalid_argument){
		if(conWidth <= 0 || conLength <= 0){
			throw invalid_argument("");
		}
		setWidth(conWidth);    // constructor with parameter
		setLength(conLength);
		setRiDownX(conRDX);
		setRiDownY(conRDY);

	}
	Rectangle::Rectangle()noexcept{    // constructor with no parameter
	}	
	double Rectangle::getWidth()const{
		return width;  

	}
	double Rectangle::getLength()const{            //getter functions for variables
		return length;

	}
	inline double Rectangle::getRiDownX()const{
		return riDownX;

	}
	inline double Rectangle::getRiDownY()const{
		return riDownY;

	}
	void Rectangle::setWidth(double sWidth){
		width = sWidth;
	}
	void Rectangle::setLength(double sLength){       //setter functions for variables
		length = sLength;
	}
	void Rectangle::setRiDownX(double sRiDownX){
		riDownX = sRiDownX;
	}
	void Rectangle::setRiDownY(double sRiDownY){
		riDownY = sRiDownY;
	}
	Rectangle& Rectangle::operator++(){
		setRiDownX(riDownX+1.0);
		setRiDownY(riDownY+1.0);
		return *this;

	}
	Rectangle& Rectangle::operator++(int ignoreMe){
		double tempRDX,tempRDY;
		tempRDX = getRiDownX();
		tempRDY = getRiDownY();
		Rectangle newRec(getWidth(),getLength(),tempRDX,tempRDY);
		setRiDownX(riDownX+1.0);
		setRiDownY(riDownY+1.0);
		return newRec;
	

	}
	Rectangle& Rectangle::operator--(){
		setRiDownX(riDownX-1.0);
		setRiDownY(riDownY-1.0);
		return *this;


	}
	Rectangle& Rectangle::operator--(int ignoreMe){
		double tempRDX,tempRDY;
		tempRDX = getRiDownX();
		tempRDY = getRiDownY();
		Rectangle newRec(getWidth(),getLength(),tempRDX,tempRDY);
		setRiDownX(riDownX-1.0);
		setRiDownY(riDownY-1.0);
		return newRec;
	}



	Rectangle& Rectangle::operator+(double num)const{
		Rectangle newRec(getWidth()+num,getLength()+num,getRiDownX(),getRiDownY());
		return newRec;





	}
	Rectangle& Rectangle::operator-(double num)const{
		Rectangle newRec(getWidth()-num,getLength()-num,getRiDownX(),getRiDownY());
		return newRec;
	}


	double Rectangle::perimeter()const{
		return (2*(getWidth()+getLength()));

	}
	double Rectangle::area()const{
		return (getWidth()*getLength());

	}




	/*

	bool Rectangle::operator==(const Rectangle& shape)const{
		if(area()==shape.area()){
			return 1;
		}
		else{
			return 0;
		}

	}
	bool Rectangle::operator!=(const Rectangle& shape)const{
		if(area()==shape.area()){
			return 0;
		}
		else{
			return 1;
		}


	}*/
	bool Rectangle::operator<(const Rectangle& shape)const{
		if(area()<shape.area()){
			return 1;
		}
		else{
			return 0;
		}
	}
	bool Rectangle::operator>(const Rectangle& shape)const{
		if(area()>shape.area()){
			return 1;
		}
		else{
			return 0;
		}
	}
	bool Rectangle::operator<=(const Rectangle& shape)const{
		if(area()<= shape.area()){
			return 1;
		}
		else{
			return 0;
		}
	}
	bool Rectangle::operator>=(const Rectangle& shape)const{
		if(area()>= shape.area()){
			return 1;
		}
		else{
			return 0;
		}

	}

}






