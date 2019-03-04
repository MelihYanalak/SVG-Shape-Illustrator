#include "Shape.h"
#include <iostream>
using namespace std;
namespace Melih{
bool Shape::operator==(const Shape& other)const{
	if(area() == other.area()){
		return true;
	}
	return false;
}

bool Shape::operator!=(const Shape& other)const{
	if(area() == other.area()){
		return false;
	}
	return true;


}

}
