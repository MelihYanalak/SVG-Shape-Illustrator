#include "PolygonDyn.h"
using namespace Melih;
namespace Melih{

void PolygonDyn::draw(ostream& fp,string color)const{
		int i = 0;	
	fp<<"<polygon points=\"";
	while(i < size){
		fp<<pointX[i]<<","<<pointY[i]<<" ";
		i++;
	}
	fp<<"\" style=\"fill:"<<color<<";stroke:black;stroke-width:1;fill-rule:nonzero;\" />"<<endl;

	}
double PolygonDyn::area()const{
	return vArea;
}
double PolygonDyn::perimeter()const{
	return vPerimeter;
}
void PolygonDyn::setPointX(double input,int index){
	pointX[index] = input;
}
double* PolygonDyn::getPointX(){
	return pointX;
}
void PolygonDyn::setPointY(double input,int index){
	pointY[index] = input;
}
double* PolygonDyn::getPointY(){
	return pointY;
}
int PolygonDyn::getSize(){
	return size;
}





PolygonDyn::PolygonDyn(Circle& c1){
		vArea = c1.area();
		vPerimeter = c1.perimeter();
		pointX = new double[100];
		pointY = new double[100];
		pointX[0] = c1.getOriginX()-c1.getRadius();
		pointY[0] = c1.getOriginY();
		int i = 1;
		int j = 1;

		while(i < 26 && i>0){
			pointX[i] = pointX[0] + (c1.getRadius()*(1-cos(i*(3.6)*PI/180.0)));
			pointY[i] = pointY[0] - (c1.getRadius()*sin(i*(3.6)*PI/180.0));
			i++;
		}
		while(i < 51 && i> 25){
			pointY[i] = pointY[25]+ (c1.getRadius()*(1-cos(j*(3.6)*PI/180.0)));
			pointX[i] = pointX[25] + (c1.getRadius()*sin(j*(3.6)*PI/180.0));
			j++;
			i++;
		}
		j = 1;
		
		while(i < 76 && i > 50 ){
			pointX[i] = pointX[50] - (c1.getRadius()*(1-cos(j*(3.6)*PI/180.0)));
			pointY[i] = pointY[50] + (c1.getRadius()*sin(j*(3.6)*PI/180.0));
			i++;
			j++;
		}
		j = 1;
		while(i < 100 && i > 75){
			pointY[i] = pointY[75] - (c1.getRadius()*(1-cos(j*(3.6)*PI/180.0)));
			pointX[i] = pointX[75] - (c1.getRadius()*sin(j*(3.6)*PI/180.0));
			i++;
			j++;
		}
		
		size = 100;



	}
	PolygonDyn::PolygonDyn(Rectangle& r1){
		vArea = r1.area();
		vPerimeter = r1.perimeter();
		pointX = new double[4];
		pointY = new double[4];
		pointX[0] = (r1.getRiDownX())-r1.getWidth();
		pointY[0] = (r1.getRiDownY())-r1.getLength();
		pointX[1] = r1.getRiDownX();
		pointY[1] = (r1.getRiDownY())-(r1.getLength());
		pointX[2] = r1.getRiDownX();
		pointY[2] = r1.getRiDownY();
		pointX[3] = (r1.getRiDownX())-(r1.getWidth());
		pointY[3] = r1.getRiDownY();
		size = 4;
	}
	PolygonDyn::PolygonDyn(Triangle& t1){
		vArea = t1.area();
		vPerimeter = t1.perimeter();
		pointX = new double[3];
		pointY = new double[3];
		pointX[0] = t1.getLeftX();
		pointY[0] = t1.getLeftY();
		pointX[1] = t1.getMidX();
		pointY[1] = t1.getMidY();
		pointX[2] = t1.getRightX();
		pointY[2] = t1.getRightY();
		size = 3;
	}


	PolygonDyn& PolygonDyn::operator++(){
		for(int i = 0;i<size;i++){
			pointX[i]++;
			pointY[i]++;
		}
		return *this;
        }
	PolygonDyn& PolygonDyn::operator++(int ignoreMe){
		PolygonDyn temp = *this;
		for(int i = 0;i<size;i++){
			pointX[i]++;
			pointY[i]++;
		}
		return temp;
	}
	PolygonDyn& PolygonDyn::operator--(){
		for(int i = 0;i<size;i++){
			pointX[i]--;
			pointY[i]--;
		}
		return *this;
	}
	PolygonDyn& PolygonDyn::operator--(int ignoreMe){
		PolygonDyn temp = *this;
		for(int i = 0;i<size;i++){
			pointX[i]--;
			pointY[i]--;
		}
		return temp;
	}
}
