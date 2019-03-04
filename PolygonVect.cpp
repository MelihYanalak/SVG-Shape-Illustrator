#include "PolygonVect.h"
using namespace Melih;
namespace Melih{
void PolygonVect::draw(ostream& fp,string color)const{
		int i = 0;	
	fp<<"<polygon points=\"";
	while(i < pointX.size()){
		fp<<pointX[i]<<","<<pointY[i]<<" ";
		i++;
	}
	fp<<"\" style=\"fill:"<<color<<";stroke:black;stroke-width:1;fill-rule:nonzero;\" />"<<endl;

	}
double PolygonVect::area()const{
	return vArea;

}
double PolygonVect::perimeter()const{
	return vPerimeter;
}
void PolygonVect::setPointX(double input,int index){
	pointX[index] = input;
}
vector<double> PolygonVect::getPointX(){
	return pointX;
}
void PolygonVect::setPointY(double input,int index){
	pointY[index] = input;
}
vector<double> PolygonVect::getPointY(){
	return pointY;
}






PolygonVect::PolygonVect(Circle& c1){
		vArea = c1.area();
		vPerimeter = c1.perimeter();
		pointX.push_back(c1.getOriginX()-c1.getRadius());
		pointY.push_back(c1.getOriginY());
		int i = 1;
		int j = 1;

		while(i < 26 && i>0){
			pointX.push_back(pointX[0] + (c1.getRadius()*(1-cos(i*(3.6)*PI/180.0))));
			pointY.push_back(pointY[0] - (c1.getRadius()*sin(i*(3.6)*PI/180.0)));
			i++;
		}
		while(i < 51 && i> 25){
			pointY.push_back(pointY[25]+ (c1.getRadius()*(1-cos(j*(3.6)*PI/180.0))));
			pointX.push_back(pointX[25] + (c1.getRadius()*sin(j*(3.6)*PI/180.0)));
			j++;
			i++;
		}
		j = 1;
		
		while(i < 76 && i > 50 ){
			pointX.push_back(pointX[50] - (c1.getRadius()*(1-cos(j*(3.6)*PI/180.0))));
			pointY.push_back(pointY[50] + (c1.getRadius()*sin(j*(3.6)*PI/180.0)));
			i++;
			j++;
		}
		j = 1;
		while(i < 100 && i > 75){
			pointY.push_back(pointY[75] - (c1.getRadius()*(1-cos(j*(3.6)*PI/180.0))));
			pointX.push_back(pointX[75] - (c1.getRadius()*sin(j*(3.6)*PI/180.0)));
			i++;
			j++;
		}

	}
	PolygonVect::PolygonVect(Rectangle& r1){
		vArea = r1.area();
		vPerimeter = r1.perimeter();
		pointX.push_back((r1.getRiDownX())-r1.getWidth());
		pointY.push_back((r1.getRiDownY())-r1.getLength());
		pointX.push_back(r1.getRiDownX());
		pointY.push_back((r1.getRiDownY())-(r1.getLength()));
		pointX.push_back(r1.getRiDownX());
		pointY.push_back(r1.getRiDownY());
		pointX.push_back((r1.getRiDownX())-(r1.getWidth()));
		pointY.push_back(r1.getRiDownY());
	}
	PolygonVect::PolygonVect(Triangle& t1){
		vArea = t1.area();
		vPerimeter = t1.perimeter();
		pointX.push_back(t1.getLeftX());
		pointY.push_back(t1.getLeftY());
		pointX.push_back(t1.getMidX());
		pointY.push_back(t1.getMidY());
		pointX.push_back(t1.getRightX());
		pointY.push_back(t1.getRightY());
	}

	PolygonVect& PolygonVect::operator++(){
		for(int i = 0;i<pointX.size();i++){
			pointX[i]++;
			pointY[i]++;
		}
		return *this;
        }
	PolygonVect& PolygonVect::operator++(int ignoreMe){
		PolygonVect temp = *this;
		for(int i = 0;i<pointX.size();i++){
			pointX[i]++;
			pointY[i]++;
		}
		return temp;
	}
	PolygonVect& PolygonVect::operator--(){
		for(int i = 0;i<pointX.size();i++){
			pointX[i]--;
			pointY[i]--;
		}
		return *this;
	}
	PolygonVect& PolygonVect::operator--(int ignoreMe){
		PolygonVect temp = *this;
		for(int i = 0;i<pointX.size();i++){
			pointX[i]--;
			pointY[i]--;
		}
		return temp;
	}
}
