all: HW05

HW05:
	g++ -std=c++0x -c Shape.cpp
	g++ -std=c++0x -c Circle.cpp
	g++ -std=c++0x -c Triangle.cpp
	g++ -std=c++0x -c Rectangle.cpp
	g++ -std=c++0x -c Polygon.cpp
	g++ -std=c++0x -c PolygonVect.cpp
	g++ -std=c++0x -c PolygonDyn.cpp
	g++ -std=c++0x -c ComposedShape.cpp
	g++ -std=c++0x -c main.cpp
	g++ -o HW05 Shape.o Circle.o Triangle.o Rectangle.o Polygon.o PolygonVect.o PolygonDyn.o ComposedShape.o main.o
clean:
	rm *.o HW05
