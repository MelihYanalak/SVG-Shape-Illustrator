
#include "Shape.h"
#include "Circle.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "ComposedShape.h"
#include "Polygon.h"
#include "PolygonVect.h"
#include "PolygonDyn.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cmath>//I used power function to calculate square root of a number
#include <stdexcept>
#define SQR (1.73205080757) // square root of 3
#define SQR2 (1.41421) // square root of 2
#define PI (3.14159265) // the number of pi
using namespace std;
using namespace Melih;
ostream& operator<<(ostream& fp,const Shape& shape){
	shape.draw(fp,"green");
	return fp;
	
}
void printAll(ostream& fp,vector<Shape*> vec)throw(std::invalid_argument){
	if(vec.size() <= 0){
		throw invalid_argument("");
	}
	for(int i=0;i<vec.size();i++){
		fp<<(*vec[i]);
	}
}

void printPoly(ostream& fp,vector<Shape*> vec)throw(std::invalid_argument){
	if(vec.size() <= 0){
		throw invalid_argument("");
	}	
	int i = 0;
	
	while(i<vec.size()){
		if(typeid(*vec[i]).name() == typeid(PolygonDyn).name() || typeid(*vec[i]).name() == typeid(PolygonVect).name()){
			fp<<(*vec[i]);
		}
		i++;
	}

}
vector<Shape*> convertAll(vector<Shape*> vec)throw(std::invalid_argument) {
	if(vec.size() <= 0){
		throw invalid_argument("");
	}
	vector<Shape*> newVec;
	int i = 0;
	while(i<vec.size()){
		if(typeid(*vec[i]).name() == typeid(Circle).name()){
			newVec.push_back(new PolygonVect((Circle&)*vec[i]));

		}
		else if(typeid(*vec[i]).name() == typeid(Triangle).name()){
			newVec.push_back(new PolygonVect((Triangle&)*vec[i]));

		}
		else if(typeid(*vec[i]).name() == typeid(Rectangle).name()){
			newVec.push_back(new PolygonVect((Rectangle&)*vec[i]));

		}
		else if(typeid(*vec[i]).name() == typeid(PolygonVect).name() || typeid(*vec[i]).name() == typeid(PolygonDyn).name() ){
			newVec.push_back(vec[i]);

		}
		i++;

	}
	return newVec;


}

vector<Shape*> sortShapes(vector<Shape*> vecP)throw(std::invalid_argument){
	if(vecP.size() <= 0){
		throw invalid_argument("");
	}	
	int i,j;
	Shape* temp;
        for (i = 0; i < vecP.size(); ++i) 
        {
 
            for (j = i + 1; j < vecP.size(); ++j)
            {
 
                if (vecP[i]->area() > vecP[j]->area()) 
                {
 
                    temp =  vecP[i];
                    vecP[i] = vecP[j];
                    vecP[j] = temp;
 
                }
 
            }
 
        }
	return vecP;

}


int main(){
	ofstream fp;
	
	
	try{
		Triangle t1(200);
		Rectangle r1(300,200);
		Circle c2(25,300,300);
		Circle c1(300);
		ComposedShape cs(c1,c2);
		PolygonVect p1(r1);
		PolygonDyn p2(c1);
		vector<Shape*> vec;
		vec.push_back(&p2);
		vec.push_back(&p1);
		vec.push_back(&c2);
		vec.push_back(&t1);
		fp.open("ComposedShape.svg");
		fp<<"<svg>"<<endl;
		fp<<cs;                 // printing composed Shape
		fp<<"</svg>"<<endl;
		fp.close();
		fp.open("printPoly.svg");         // printing only polygonVect or polygonDyn objects
		fp<<"<svg>"<<endl;
		printPoly(fp,vec);
		
		fp<<"</svg>"<<endl;
		fp.close();
		fp.open("printAll.svg");     // Printing all of them
		fp<<"<svg>"<<endl;
		printAll(fp,vec);
		fp<<"</svg>"<<endl;
		fp.close();
		vec = convertAll(vec);        // converting each shape to polygonvect and polygonDyn
		fp.open("printPoly2.svg");    
		fp<<"<svg>"<<endl;
		printPoly(fp,vec);            // Then it will print all the elements of vector to file
		
		fp<<"</svg>"<<endl;
		fp.close();
		int i = 0;
		while(i<(vec.size()-1)){
			for(int j = 0;j<40;j++){    // Increasing the coordinates of shapes
				++(*vec[i]);
			}
			i++;
		}
		fp.open("afterMoving.svg");    // Printing after moving
		fp<<"<svg>"<<endl;
		printAll(fp,vec);
		fp<<"</svg>"<<endl;
		fp.close();
		i = 0;
		cout<<"PERIMETER OF EACH SHAPE"<<endl;
		while(i<vec.size()){
			cout<<(vec[i]->perimeter())<<endl;   // Virtual perimeter function
			i++;
		}
		cout<<endl<<"AREA OF EACH SHAPE"<<endl;
		i = 0;
		while(i<vec.size()){
			cout<<(vec[i]->area())<<endl;    // Virtual area function
			i++;
		}
		vec = sortShapes(vec);    // sorting the vector with respect to their area increasingly
		i = 0;
		cout<<endl<<"AFTER SORTING THEM"<<endl;
		while(i<vec.size()){
			cout<<(vec[i]->area())<<endl;   // Prints after sorting
			i++;
		}
		cout<<endl<<"COMPARISON"<<endl;  // virtual == and != operators
		cout<<"Area of first shape != Area of second shape --> "<<(vec[0]->area() != vec[1]->area())<<endl;
		cout<<"Area of first shape == Area of second shape --> "<<(vec[0]->area() == vec[1]->area())<<endl; 
		
	}
	catch(exception e){    // for possible errors
		cout<<"Invalid Argument"<<endl;
	}
	
	
	


	return 1;
}



