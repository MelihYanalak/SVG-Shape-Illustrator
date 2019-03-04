#include "ComposedShape.h"
#include "Shape.h"
#include "Circle.h"
#include "Triangle.h"
#include "Rectangle.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#define SQR (1.73205080757) // square root of 3
#define SQR2 (1.41421) // square root of 2
#define PI (3.14159265) // the number of pi
using namespace std;
using namespace Melih;
namespace Melih{
	ComposedShape::ComposedShape(Rectangle bigR,Rectangle smallR){
		situation = 1;
		containerR.setWidth(bigR.getWidth());
		containerR.setLength(bigR.getLength());
		centerX = containerR.getWidth()/2;
		centerY = containerR.getLength()/2;              // Constructor with parameter big Rectangle and small Rectangles in it
		containerR.setRiDownX(centerX+(containerR.getWidth()/2));
		containerR.setRiDownY(centerY+(containerR.getLength()/2));
		
		innerR.setWidth(smallR.getWidth());
		innerR.setLength(smallR.getLength());
		container = &containerR;
		optimalFit();

	}
	
	ComposedShape::ComposedShape(Rectangle bigR,Circle smallC){
		situation = 2;
		containerR.setWidth(bigR.getWidth());
		containerR.setLength(bigR.getLength());
		centerX = containerR.getWidth()/2;
		centerY = containerR.getLength()/2;         // Constructor with parameter big Rectangle and small circles in it
		containerR.setRiDownX(centerX+(containerR.getWidth()/2));
		containerR.setRiDownY(centerY+(containerR.getLength()/2));

		innerC.setRadius(smallC.getRadius());
		container = &containerR;
		optimalFit();

	}
	ComposedShape::ComposedShape(Rectangle bigR,Triangle smallT){
		situation = 3;
		containerR.setWidth(bigR.getWidth());
		containerR.setLength(bigR.getLength());  // Constructor with parameter big Rectangle and small triangles in it
		centerX = containerR.getWidth()/2;
		centerY = containerR.getLength()/2;
		containerR.setRiDownX(centerX+(containerR.getWidth()/2));
		containerR.setRiDownY(centerY+(containerR.getLength()/2));


		innerT.setSide(smallT.getSide());
		container = &containerR;
		optimalFit();


	}

	ComposedShape::ComposedShape(Circle bigC,Rectangle smallR){
	
		situation = 4;
		containerC.setRadius(bigC.getRadius());
		center = containerC.getRadius();
		containerC.setOriginX(center);
		containerC.setOriginY(center);    // Constructor with parameter big Circle and small Rectangles in it

		innerR.setWidth(smallR.getWidth());
		innerR.setLength(smallR.getLength());
		container = &containerC;
		optimalFit();

	}
	ComposedShape::ComposedShape(Circle bigC,Circle smallC){
	
		situation = 5;
		containerC.setRadius(bigC.getRadius());
		center = containerC.getRadius();
		containerC.setOriginX(center);      // Constructor with parameter big Circle and small circles in it
		containerC.setOriginY(center);
		innerC.setRadius(smallC.getRadius());
		container = &containerC;
		optimalFit();
	}
	ComposedShape::ComposedShape(Circle bigC,Triangle smallT){
	
		situation = 6;
		containerC.setRadius(bigC.getRadius());
		center = containerC.getRadius();
		containerC.setOriginX(center);    // Constructor with parameter big Circle and small Triangles in it
		containerC.setOriginY(center);
		innerT.setSide(smallT.getSide());
		container = &containerC;
		optimalFit();
	}

	ComposedShape::ComposedShape(Triangle bigT,Rectangle smallR){
		situation = 7;
		
		containerT.setSide(bigT.getSide());
		centerX = bigT.getSide()/2;
		centerY = bigT.getSide()*SQR/3;
		containerT.setLeftX(centerX-(containerT.getSide()/2));
		containerT.setLeftY(centerY+(containerT.getSide()*SQR/6));     // Constructor with parameter big Triangle and small recs in it
		containerT.setMidX(centerX);
		containerT.setMidY(centerY-(containerT.getSide()*SQR/3));
		containerT.setRightX(centerX+(containerT.getSide()/2));
		containerT.setRightY(centerY + (containerT.getSide()*SQR/6));	
		innerR.setWidth(smallR.getWidth());
		innerR.setLength(smallR.getLength());
		container = &containerT;
		optimalFit();

	}

	ComposedShape::ComposedShape(Triangle bigT,Circle smallC){
		situation = 8;
		containerT.setSide(bigT.getSide());
		centerX = bigT.getSide()/2;
		centerY = bigT.getSide()*SQR/3;
		   
		containerT.setLeftX(centerX-(containerT.getSide()/2));
		containerT.setLeftY(centerY+(containerT.getSide()*SQR/6));    // Constructor with parameter big Triangle and small circles in it
		containerT.setMidX(centerX);
		containerT.setMidY(centerY-(containerT.getSide()*SQR/3));
		containerT.setRightX(centerX+(containerT.getSide()/2));
		containerT.setRightY(centerY + (containerT.getSide()*SQR/6));
		container = &containerT;
		
		innerC.setRadius(smallC.getRadius());
		optimalFit();

	}

	ComposedShape::ComposedShape(Triangle bigT,Triangle smallT){
		situation = 9;
		
		containerT.setSide(bigT.getSide());
		centerX = bigT.getSide()/2;
		centerY = bigT.getSide()*SQR/3;
		containerT.setLeftX(centerX-(containerT.getSide()/2));
		containerT.setLeftY(centerY+(containerT.getSide()*SQR/6));   // Constructor with parameter big Triangle and small triangles in it
		containerT.setMidX(centerX);
		containerT.setMidY(centerY-(containerT.getSide()*SQR/3));
		containerT.setRightX(centerX+(containerT.getSide()/2));
		containerT.setRightY(centerY + (containerT.getSide()*SQR/6));
		container = &containerT;
		innerT.setSide(smallT.getSide());
		optimalFit();

	}

	 int ComposedShape::getSituation()const{     
		return situation;
	}
	 Rectangle ComposedShape::getInnerR(){
		return innerR;
	}	                                            //getter functions
	 Rectangle ComposedShape::getContainerR(){
		return containerR;
	}
	 Circle ComposedShape::getInnerC(){
		return innerC;
	}
	 Circle ComposedShape::getContainerC(){   // gets the container shape
		return containerC;
	}                                           
	 Triangle ComposedShape::getInnerT(){   // gets the small shape
		return innerT;
	}
	 Triangle ComposedShape::getContainerT(){
		return containerT;
	}



void ComposedShape::optimalFit(){
	double rightBorder,leftBorder,upBorder,downBorder;
	int countA,countB,i,count;
	double temp,endOfL,currX,upB,currY,rPX,leftX,leftY,midX,midY,rightX,rightY;
	double cLeftX,cLeftY,cMidX,cMidY,cRightX,cRightY;
	Rectangle tempR;
	int control ;
	int k = 0;
	Circle tempC;

	
	Triangle tempT;
	switch(getSituation()){

		case 1:
			rightBorder = (centerX+containerR.getWidth()/2);
			leftBorder = centerX-(containerR.getWidth()/2);
			upBorder = centerY-(containerR.getLength()/2); 
			downBorder = centerY+(containerR.getLength()/2);
			countA = 0;
			countB = 0;     

			currX= leftBorder+innerR.getWidth();
			currY = upBorder + innerR.getLength();
			while((downBorder-currY)>= 0){
				while((rightBorder-currX)>=(0)){
					countA++;
					currX = currX + innerR.getWidth();

				}
				endOfL = currX-innerR.getWidth(); // endOfL is to know where the row ends
				currX = leftBorder + innerR.getWidth();
				currY = currY + innerR.getLength();

			}

			temp = innerR.getWidth();
			innerR.setWidth(innerR.getLength()); // swapping values
			innerR.setLength(temp);
			
			currX= endOfL+innerR.getWidth();
			currY = upBorder + innerR.getLength();
			while((downBorder-currY)>= 0){
				while((rightBorder-currX)>=(0)){   // trying to fill empty places with swapping 
					countA++;
					currX = currX + innerR.getWidth();

				}
				currX = endOfL + innerR.getWidth();
				currY = currY + innerR.getLength();

			}

			//-------------------------------------
			
			currX= leftBorder+innerR.getWidth();
			currY = upBorder + innerR.getLength();
			while((downBorder-currY)>= 0){
				while((rightBorder-currX)>=(0)){      // changed sides and try like this
					countB++;
					currX = currX + innerR.getWidth();

				}
				currX = leftBorder + innerR.getWidth();
				currY = currY + innerR.getLength();

			}
			upB = currY-innerR.getLength();
			
				
			temp = innerR.getWidth();
			innerR.setWidth(innerR.getLength());
			innerR.setLength(temp);
			
			currX= leftBorder+innerR.getWidth();
			currY = upB + innerR.getLength();
			while((downBorder-currY)>= 0){
				while((rightBorder-currX)>=(0)){
					countB++;
					currX = currX + innerR.getWidth();

				}
				currX = leftBorder + innerR.getWidth();
				currY = currY + innerR.getLength();

			}
			if(countA >= countB){
				int i = 0;
				k = 0;
				currX= leftBorder+innerR.getWidth();
				currY = upBorder + innerR.getLength();
				while((downBorder-currY)>= 0){
					while((rightBorder-currX)>=(0)){					
						
						innerShapes.push_back(new Rectangle(innerR.getWidth(),innerR.getLength(),currX,currY));
						currX = currX + innerR.getWidth();

					}
					endOfL = currX-innerR.getWidth();
					currX = leftBorder + innerR.getWidth();
					currY = currY + innerR.getLength();

				}
							
				temp = innerR.getWidth();
				innerR.setWidth(innerR.getLength());
				innerR.setLength(temp);
				
				currX= endOfL+innerR.getWidth();
				currY = upBorder + innerR.getLength();
				while((downBorder-currY)>= 0){
					while((rightBorder-currX)>=(0)){
						innerShapes.push_back(new Rectangle(innerR.getWidth(),innerR.getLength(),currX,currY));
						k++;
						currX = currX + innerR.getWidth();

					}
					currX = endOfL + innerR.getWidth();
					currY = currY + innerR.getLength();

				}

			}
			
			else if(countB > countA){
				k = 0;
				temp = innerR.getWidth();
				innerR.setWidth(innerR.getLength());
				innerR.setLength(temp);
				currX= leftBorder+innerR.getWidth();
				currY = upBorder + innerR.getLength();
				while((downBorder-currY)>= 0){
					while((rightBorder-currX)>=(0)){
						innerShapes.push_back(new Rectangle(innerR.getWidth(),innerR.getLength(),currX,currY));
						k++;
						currX = currX + innerR.getWidth();

					}
					currX = leftBorder + innerR.getWidth();
					currY = currY + innerR.getLength();

				}
				upB = currY-innerR.getLength();
				
					
				temp = innerR.getWidth();
				innerR.setWidth(innerR.getLength());
				innerR.setLength(temp);
				
				currX= leftBorder+innerR.getWidth();
				currY = upB + innerR.getLength();
				while((downBorder-currY)>= 0){
					while((rightBorder-currX)>=(0)){
						innerShapes.push_back(new Rectangle(innerR.getWidth(),innerR.getLength(),currX,currY));
						k++;
						currX = currX + innerR.getWidth();

					}
					currX = leftBorder + innerR.getWidth();
					currY = currY + innerR.getLength();

				}


			}

			break;
	
		case 2:
			control = 0;
			countA = 0;
			countB = 0;
			rightBorder = (centerX+containerR.getLength()/2);
			leftBorder = centerX-(containerR.getLength()/2);   // calculating borders
			upBorder = centerY-(containerR.getLength()/2);
			downBorder = centerY+(containerR.getLength()/2);
			currX = leftBorder + innerC.getRadius();
			currY = upBorder + innerC.getRadius();
			while((downBorder-currY)>=((innerC.getRadius())*SQR/2)){
				if(control%2 == 1){
					currX = leftBorder + (2*innerC.getRadius());
				}
				else if(control%2 == 0){
					currX = leftBorder + innerC.getRadius();
				}
				while((rightBorder-currX)>= (innerC.getRadius())){    // I just count and compare below if it's better algorithm or not for input
					countA++;
					currX = currX + (2*innerC.getRadius());
				}
				control++;
				currY = currY + ((innerC.getRadius())*SQR);
			}

			control = 0;
			currX = leftBorder + innerC.getRadius();
			currY = upBorder + innerC.getRadius();
			while((downBorder-currY)>=((innerC.getRadius())*SQR/2)){
				if(control%2 == 1){
					currX = leftBorder + (2*innerC.getRadius());
				}
				else if(control%2 == 0){                       // second algorithm to place them
					currX = leftBorder + innerC.getRadius();
				}
				while((rightBorder-currX)>= (innerC.getRadius())){
					countB++;
					currX = currX + (2*innerC.getRadius());
				}
				currY = currY + ((innerC.getRadius())*2);
			}
			if(countA >= countB){
				currX = leftBorder + innerC.getRadius();
				currY = upBorder + innerC.getRadius();
				while((downBorder-currY)>=((innerC.getRadius())*SQR/2)){
					if(control%2 == 1){
						currX = leftBorder + (2*innerC.getRadius());
					}
					else if(control%2 == 0){
						currX = leftBorder + innerC.getRadius();    // choosing which algorithm is better
					}
					while((rightBorder-currX)>= (innerC.getRadius())){
						innerShapes.push_back(new Circle(innerC.getRadius(),currX,currY));
						k++;
						currX = currX + (2*innerC.getRadius());
					}
					control++;
					currY = currY + ((innerC.getRadius())*SQR);
				}

			}
			else if(countB > countA){
				currX = leftBorder + innerC.getRadius();
				currY = upBorder + innerC.getRadius();
				while((downBorder-currY)>=((innerC.getRadius())*SQR/2)){
					if(control%2 == 1){
						currX = leftBorder + (2*innerC.getRadius());
					}
					else if(control%2 == 0){
						currX = leftBorder + innerC.getRadius();           // If B > A we place normally
					}
					while((rightBorder-currX)>= (innerC.getRadius())){
						innerShapes.push_back(new Circle(innerC.getRadius(),currX,currY));
						k++;
						currX = currX + (2*innerC.getRadius());
					}
					currY = currY + ((innerC.getRadius())*2);
				}			
			}
			
			break;

		
		case 3:

			
			control = 0;
			count = 0;
			rightBorder = (centerX+containerR.getWidth()/2);
			leftBorder = centerX-(containerR.getWidth()/2); // calculating borders
			upBorder = centerY-(containerR.getLength()/2);
			downBorder = centerY+(containerR.getLength()/2);
			cLeftX = leftBorder;
			cLeftY = upBorder+((innerT.getSide()/2)* SQR);	// calculating corner points of starting small triangle
			cMidX = leftBorder + (innerT.getSide()/2);
			cMidY = upBorder;
			cRightX = leftBorder + (innerT.getSide());
			cRightY = upBorder + ((innerT.getSide()/2)*SQR);
			
			while((downBorder-cLeftY)>=((innerT.getSide()/2)*SQR)||(downBorder-cMidY) >= ((innerT.getSide()/2)* SQR) || (downBorder-cRightY)>=((innerT.getSide()/2)* SQR)){
				while((rightBorder-cMidX) >= (innerT.getSide()*1)/2){
					
					if(control%2==1){
						cLeftY = cLeftY- ((innerT.getSide()/2)*SQR);
						cMidY = cMidY + ((innerT.getSide()/2)*SQR);	  // I rotate the triangle degree of 180 here 			
						cRightY = cRightY - ((innerT.getSide()/2)*SQR);
					}
					else if(control%2 == 0 && control != 0){
						cLeftY = cLeftY+ ((innerT.getSide()/2)*SQR);
						cMidY = cMidY - ((innerT.getSide()/2)*SQR);				
						cRightY = cRightY + ((innerT.getSide()/2)*SQR);
					}
					innerShapes.push_back(new Triangle(innerT.getSide(),cLeftX,cLeftY,cMidX,cMidY,cRightX,cRightY));
					k++;
					count++;
					cLeftX = cLeftX + (innerT.getSide()/2);
					cMidX = cMidX + (innerT.getSide()/2);
					cRightX = cRightX + (innerT.getSide()/2);
					control++;
				}
				control = 0;
				cLeftX = leftBorder;
				cMidX = leftBorder + (innerT.getSide()/2);
				cRightX = leftBorder + (innerT.getSide());
				cLeftY = cLeftY + ((innerT.getSide()/2)*SQR); // after finishing row,changing coordinates
				cMidY = cMidY + ((innerT.getSide()/2)*SQR);
				cRightY = cRightY + ((innerT.getSide()/2)*SQR);

			}
			break;

		
		case 4:
			rightBorder = (center+containerC.getRadius()/SQR2);
			leftBorder = center-(containerC.getRadius()/SQR2);
			upBorder = center-(containerC.getRadius()/SQR2);
			downBorder = center+(containerC.getRadius()/SQR2);
			countA = 0;
			countB = 0;                         // I created imaginary the biggest square inside circle and fill like it's a square
			currX= leftBorder+innerR.getWidth();
			currY = upBorder + innerR.getLength();
			while((downBorder-currY)>= 0){
				while((rightBorder-currX)>=(0)){
					countA++;                       // I don't draw here i just count
					currX = currX + innerR.getWidth();	// Horizontal

				}
				endOfL = currX-innerR.getWidth();
				currX = leftBorder + innerR.getWidth();
				currY = currY + innerR.getLength();

			}
			
			temp = innerR.getWidth();
			innerR.setWidth(innerR.getLength());
			innerR.setLength(temp);
			
			currX= endOfL+innerR.getWidth();
			currY = upBorder + innerR.getLength();
			while((downBorder-currY)>= 0){                  //Finished horizontal but trying to fill it with vertical
				while((rightBorder-currX)>=(0)){     
					countA++;
					currX = currX + innerR.getWidth();

				}
				currX = endOfL + innerR.getWidth();
				currY = currY + innerR.getLength();

			}

			//-------------------------------------
			
			currX= leftBorder+innerR.getWidth();
			currY = upBorder + innerR.getLength();
			while((downBorder-currY)>= 0){
				while((rightBorder-currX)>=(0)){        // Vertical starting
					countB++;
					currX = currX + innerR.getWidth();

				}
				currX = leftBorder + innerR.getWidth();
				currY = currY + innerR.getLength();

			}
			upB = currY-innerR.getLength();
			
				
			temp = innerR.getWidth();
			innerR.setWidth(innerR.getLength());
			innerR.setLength(temp);
			
			currX= leftBorder+innerR.getWidth();
			currY = upB + innerR.getLength();
			while((downBorder-currY)>= 0){
				while((rightBorder-currX)>=(0)){     //Filling missing parts vertically
					countB++;
					currX = currX + innerR.getWidth();

				}
				currX = leftBorder + innerR.getWidth();
				currY = currY + innerR.getLength();

			}
			if(countA >= countB){
					currX= leftBorder+innerR.getWidth();
				currY = upBorder + innerR.getLength();
				while((downBorder-currY)>= 0){
					while((rightBorder-currX)>=(0)){

						innerShapes.push_back(new Rectangle(innerR.getWidth(),innerR.getLength(),currX,currY));
						k++;
						currX = currX + innerR.getWidth();

					}
					endOfL = currX-innerR.getWidth();
					currX = leftBorder + innerR.getWidth();
					currY = currY + innerR.getLength();

				}
				temp = innerR.getWidth();
				innerR.setWidth(innerR.getLength());
				innerR.setLength(temp);
				
				currX= endOfL+innerR.getWidth();
				currY = upBorder + innerR.getLength();
				while((downBorder-currY)>= 0){
					while((rightBorder-currX)>=(0)){
						innerShapes.push_back(new Rectangle(innerR.getWidth(),innerR.getLength(),currX,currY));
						k++;
						currX = currX + innerR.getWidth();

					}
					currX = endOfL + innerR.getWidth();
					currY = currY + innerR.getLength();

				}

				

			}
			
			else if(countB > countA){
				temp = innerR.getWidth();
				innerR.setWidth(innerR.getLength());
				innerR.setLength(temp);
				currX= leftBorder+innerR.getWidth();
				currY = upBorder + innerR.getLength();      // IF B > A    I FILL VERTICALLY
				while((downBorder-currY)>= 0){
					while((rightBorder-currX)>=(0)){
						innerShapes.push_back(new Rectangle(innerR.getWidth(),innerR.getLength(),currX,currY));
						k++;
						currX = currX + innerR.getWidth();

					}
					currX = leftBorder + innerR.getWidth();
					currY = currY + innerR.getLength();

				}
				upB = currY-innerR.getLength();
				
					
				temp = innerR.getWidth();
				innerR.setWidth(innerR.getLength());
				innerR.setLength(temp);
				
				currX= leftBorder+innerR.getWidth();
				currY = upB + innerR.getLength();
				while((downBorder-currY)>= 0){
					while((rightBorder-currX)>=(0)){
					  // TRY TO FILL HORIZONTAL IN THE END	
						innerShapes.push_back(new Rectangle(innerR.getWidth(),innerR.getLength(),currX,currY));
						k++;
						currX = currX + innerR.getWidth();

					}
					currX = leftBorder + innerR.getWidth();
					currY = currY + innerR.getLength();

				}


			
			break;
	
		
		case 5:
			
			control = 0;
			count = 0;
			rightBorder = (center+(containerC.getRadius()*2)/2);
			leftBorder = center-((containerC.getRadius()*2)/2);  // i created imaginary smallest square shape that include container circle 
			upBorder = center-((containerC.getRadius()*2)/2);	// i calculated the borders coordinates
			downBorder = center+((containerC.getRadius()*2)/2);
			currX = leftBorder + innerC.getRadius();  // we will move with these 2 variables in loop
			currY = upBorder + innerC.getRadius();
			while((downBorder-currY)>=((innerC.getRadius())*SQR)){
				if(control%2 == 1){
					currX = leftBorder + (2*innerC.getRadius()); // control variable for determine starting point of every column
				}
				else if(control%2 == 0){
					currX = leftBorder + innerC.getRadius();
				}
				while((rightBorder-currX)>= (innerC.getRadius())){
					if(pow((center-currX)*(center-currX)+(center-currY)*(center-currY),0.5)<=(containerC.getRadius()-innerC.getRadius())){
					// I used geometrical distance formula to determine if the circuit inside a container or not
					innerShapes.push_back(new Circle(innerC.getRadius(),currX,currY));
					k++;
					count++;
					}
					currX = currX + (2*innerC.getRadius());
				}
				control++;
				currY = currY + ((innerC.getRadius())*SQR);
			}

			break;

	
		
		case 6:
			
			control = 0;
			count = 0;
			rightBorder = (center+containerC.getRadius()*SQR2/2);
			leftBorder = center-(containerC.getRadius()*SQR2/2);
			upBorder = center-(containerC.getRadius()*SQR2/2);    // I drawed imaginary biggest square in circle and fill it
			downBorder = center+(containerC.getRadius()*SQR2/2);
			cLeftX = leftBorder;
			cLeftY = upBorder+((innerT.getSide()/2)* SQR); // Calculating corner points
			cMidX = leftBorder + (innerT.getSide()/2);
			cMidY = upBorder;
			cRightX = leftBorder + (innerT.getSide());
			cRightY = upBorder + ((innerT.getSide()/2)*SQR);
			while((downBorder-cLeftY)>=((innerT.getSide()/2)*SQR)||(downBorder-cMidY) >= ((innerT.getSide()/2)* SQR) || (downBorder-cRightY)>=((innerT.getSide()/2)* SQR)){
				while((rightBorder-cMidX) >= (innerT.getSide()*1)/2){
					if(control%2==1){
						cLeftY = cLeftY- ((innerT.getSide()/2)*SQR);
						cMidY = cMidY + ((innerT.getSide()/2)*SQR);				
						cRightY = cRightY - ((innerT.getSide()/2)*SQR);
					}
					else if(control%2 == 0 && control != 0){
						cLeftY = cLeftY+ ((innerT.getSide()/2)*SQR);
						cMidY = cMidY - ((innerT.getSide()/2)*SQR);				
						cRightY = cRightY + ((innerT.getSide()/2)*SQR);
					}
					innerShapes.push_back(new Triangle(innerT.getSide(),cLeftX,cLeftY,cMidX,cMidY,cRightX,cRightY));
					k++;
					count++;  // counting to calculate area
					cLeftX = cLeftX + (innerT.getSide()/2);
					cMidX = cMidX + (innerT.getSide()/2);
					cRightX = cRightX + (innerT.getSide()/2);
					control++;
				}
				control = 0;
				cLeftX = leftBorder;
				cMidX = leftBorder + (innerT.getSide()/2);
				cRightX = leftBorder + (innerT.getSide());
				cLeftY = cLeftY + ((innerT.getSide()/2)*SQR);
				cMidY = cMidY + ((innerT.getSide()/2)*SQR);
				cRightY = cRightY + ((innerT.getSide()/2)*SQR);


			}
			break;

		
		case 7:
	

			countA = 0;
			countB = 0;
			leftX = centerX-(containerT.getSide()/2);
			leftY = centerY + (containerT.getSide()*SQR/6);
			midX = centerX;
			midY = centerY-(containerT.getSide()*SQR/3); // calculating corner points of triangle
			rightX =  centerX+(containerT.getSide()/2);
			rPX = rightX;
			rightY = centerY + (containerT.getSide()*SQR/6)- ((innerR.getLength())/SQR);
			currX = leftX + ((innerR.getLength())/SQR);
			currY = leftY - innerR.getLength();
			i = 1;
			while((currY-midY)>=innerR.getLength()/2){
				while((rPX-currX)>=(innerR.getWidth()*2)){
					countA++;
					currX = currX + innerR.getWidth();
				}                                      // counting to choose better algorithm
				i++;
				rPX = rPX - (innerR.getLength()/SQR);
				currX = leftX + i*(innerR.getLength()/SQR);
				currY = currY - (innerR.getLength());

			}
			temp = innerR.getWidth();
			innerR.setWidth(innerR.getLength());
			innerR.setLength(temp);
			rPX = rightX;
			currX = leftX + ((innerR.getLength())/SQR);
			currY = leftY - innerR.getLength();
			while((currY-midY)>=innerR.getLength()/2){
				while((rPX-currX)>=(innerR.getWidth()*2)){   
					countB++;
					currX = currX + innerR.getWidth();
				}
				i++;					// counting to choose better algorithm
				rPX = rPX - (innerR.getLength()/SQR);
				currX = leftX + i*(innerR.getLength()/SQR);
				currY = currY - (innerR.getLength());

			}
			i = 1;
			if(countA >= countB){
				temp = innerR.getWidth();
				innerR.setWidth(innerR.getLength());
				innerR.setLength(temp);
				rPX = rightX;
				currX = leftX + ((innerR.getLength())/SQR);
				currY = leftY - innerR.getLength();			// if A > B place them horizontally
				while((currY-midY)>=innerR.getLength()/2){
					while((rPX-currX)>=(innerR.getWidth()*2)){
						innerShapes.push_back(new Rectangle(innerR.getWidth(),innerR.getLength(),currX,currY));
						k++;
						currX = currX + innerR.getWidth();
					}
					i++;
					rPX = rPX - (innerR.getLength()/SQR);
					currX = leftX + i*(innerR.getLength()/SQR);
					currY = currY - (innerR.getLength());

				}



			}
			else if(countA < countB){
				rPX = rightX;
				currX = leftX + ((innerR.getLength())/SQR);
				currY = leftY - innerR.getLength();
				while((currY-midY)>=innerR.getLength()/2){
					while((rPX-currX)>=(innerR.getWidth()*2)){
						innerShapes.push_back(new Rectangle(innerR.getWidth(),innerR.getLength(),currX,currY));
						k++;
						currX = currX + innerR.getWidth();	// if B > A place them vertically
					}
					i++;
					rPX = rPX - (innerR.getLength()/SQR);
					currX = leftX + i*(innerR.getLength()/SQR);
					currY = currY - (innerR.getLength());

				}


			
			break;
		case 8:


			leftX = centerX-(containerT.getSide()/2);
			leftY = centerY + (containerT.getSide()*SQR/6);
			midX = centerX;                      // calculating coordinates of triangle
			midY = centerY-(containerT.getSide()*SQR/3);
			rightX =  centerX+(containerT.getSide()/2);
			rightY = centerY + (containerT.getSide()*SQR/6);
			i = 0;
			count = 0;
			currX = leftX + (innerC.getRadius()*SQR);   
			currY = leftY - innerC.getRadius();
			
			while((currY-midY)>=innerC.getRadius()){
				while((rightX-currX)>=(innerC.getRadius()*SQR)){
					innerShapes.push_back(new Circle(innerC.getRadius(),currX,currY));
					k++;
					count++;
					currX = currX+ (innerC.getRadius()*2); // it moves horizontally

				}
				i++;
				rightX = rightX - (innerC.getRadius()); // right corner getting shorter each row
				currX = leftX + (innerC.getRadius()*SQR)+ (i*innerC.getRadius());
				currY = currY - (innerC.getRadius()*SQR);

			}
			break;
			
		case 9:


			leftX = centerX-(containerT.getSide()/2);
			leftY = centerY + (containerT.getSide()*SQR/6);
			midX = centerX;
			midY = centerY-(containerT.getSide()*SQR/3);
			rightX =  centerX+(containerT.getSide()/2);
			rightY = centerY + (containerT.getSide()*SQR/6); // we calculate big triangle coordinates and also for starting one
			cLeftX = leftX;
			cLeftY = leftY;
			cMidX = leftX + (innerT.getSide()/2);
			cMidY = leftY - ((innerT.getSide())*SQR/2);
			cRightX = cLeftX + (innerT.getSide());
			cRightY = cLeftY;
			control = 0;
			count = 0;
			i = 0;
			while((cMidY-midY)>=0 ){
				while((rightX-cRightX) >= 0){
					
					if(control%2==1){
						cLeftY = cLeftY- ((innerT.getSide()/2)*SQR);
						cMidY = cMidY + ((innerT.getSide()/2)*SQR);		//rotating triangle to place more		
						cRightY = cRightY - ((innerT.getSide()/2)*SQR);
					}
					else if(control%2 == 0 && control != 0){
						cLeftY = cLeftY+ ((innerT.getSide()/2)*SQR);
						cMidY = cMidY - ((innerT.getSide()/2)*SQR);				
						cRightY = cRightY + ((innerT.getSide()/2)*SQR);
					}
					innerShapes.push_back(new Triangle(innerT.getSide(),cLeftX,cLeftY,cMidX,cMidY,cRightX,cRightY));
					k++;
					count++;
					cLeftX = cLeftX + (innerT.getSide()/2);
					cMidX = cMidX + (innerT.getSide()/2); // moving horizontally
					cRightX = cRightX + (innerT.getSide()/2);
					control++;
				}
				control = 0;
				i++;
				rightX = rightX - (innerT.getSide()/2);
				cLeftX = leftX + (i*innerT.getSide()/2);
				cMidX = cLeftX + (innerT.getSide()/2); // moving vertically
				cRightX = cLeftX + (innerT.getSide());
				cLeftY = cLeftY - ((innerT.getSide()/2)*SQR);
				cMidY = cMidY - ((innerT.getSide()/2)*SQR);
				cRightY = cRightY - ((innerT.getSide()/2)*SQR);


			}
			break;
		

	}

	}

	}

}
double ComposedShape::area()const{
	return (container->area());
}
double ComposedShape::perimeter()const{
	return container->perimeter();
}
ComposedShape& ComposedShape::operator++(){
	return *this;
}
ComposedShape& ComposedShape::operator++(int ignoreMe){
	return *this;
}
ComposedShape& ComposedShape::operator--(){
	return *this;
}
ComposedShape& ComposedShape::operator--(int ignoreMe){
	return *this;
}
void ComposedShape::draw(ostream& fp,string color)const{
	container->draw(fp,"green");
	for(int i = 0;i<innerShapes.size();i++){
		innerShapes[i]->draw(fp,"red");
	}
}
}



