// TestProject2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Shape {

private:
	int width;
	int height;
	string name;

	static int numberOfShapes;
public:

	//Constructor
	Shape();
	Shape(string name);
	Shape(int width, int height, string name);

	//Destructor
	~Shape();

	//Setters and Getters;
	int getHeight() { return height; };
	void setHeight(int height) { this->height = height; };
	int getWidth() {};
	void setWidth(int width) { this->width = width; };
	string getName() { return name; }
	void setName(string name) { this->name = name; }
	void setAll(int, int, string);

	static int getNoOFAllShapes();

	void ToString();
};


int Shape::numberOfShapes = 0;			//Initalizing the static member in c++

void Shape::setAll(int width, int height, string name) {

	this->width = width;
	this->height = height;
	this->name = name;

}

class ArrayOfShapes {
private:
	int sizeOfArray;
public:
	Shape* shapes;
	~ArrayOfShapes();
	ArrayOfShapes(int sizeOfArray);
	int getSizeOfArray() { return sizeOfArray; }
};


ArrayOfShapes::ArrayOfShapes(int sizeOfArray) {
	this->sizeOfArray = sizeOfArray;
	this->shapes = new Shape[sizeOfArray];

}
ArrayOfShapes::~ArrayOfShapes() {
	delete shapes;
}

//int main()
//{
//	try
//	{
//		Shape square(2, 2, "Square");
//		square.ToString();
//		Shape* shapes = new Shape[4];
//		shapes[0] = Shape(3, 2, "Triangle");
//		shapes[1] = Shape(4, 2, "Rectangle");
//		shapes[0].ToString();
//		shapes[1].ToString();
//
//		cout << shapes[1].getName() << endl;
//		cout << shapes[2].getName() << endl;
//
//		Shape* quad = new Shape();
//		cout << Shape::getNoOFAllShapes() << endl;
//
//		delete(quad);
//		cout << Shape::getNoOFAllShapes() << endl;
//
//		ArrayOfShapes arrayOfShapes(3);
//
//		cout << "------------------------------------------" << endl;
//		for (int i = 0; i <= arrayOfShapes.getSizeOfArray()-1; i++) {
//			 ((Shape)arrayOfShapes.shapes[i]).ToString();
//		}
//		
//	}
//	catch (const std::exception & e)
//	{
//		cout << "Exception: " << e.what() << endl;
//	}
//
//}



int Shape::getNoOFAllShapes()
{
	return Shape::numberOfShapes;
}

void Shape::ToString()
{
	cout << "Shape name: " << this->name << endl <<
		"Shape width: " << this->width << endl <<
		"Shape height: " << this->height << endl;
}
Shape::Shape()
{
	Shape::numberOfShapes++;
	this->name = "Initial Name";
	this->height = 0;
	this->width = 0;
}

Shape::Shape(string name) :Shape()
{
	this->name = name;
}

Shape::Shape(int width, int height, string name) : Shape(name)
{
	this->width = width;
	this->height = height;
}

Shape::~Shape()
{
	Shape::numberOfShapes--;
}

