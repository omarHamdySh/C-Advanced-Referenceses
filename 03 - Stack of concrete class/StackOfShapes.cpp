//------------------------ Stack of concrete type ---------------------
//-------------------------- Pointer to Pointer -----------------------
#include <iostream>

using namespace std;
# define my_sizeof(type) ((char *)(&type+1)-(char*)(&type)) 

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
	cout << name << " is destructed"<<endl;
	Shape::numberOfShapes--;
}

class Stack
{
	int tos,size;
	Shape** stk;
public:
	Stack(int size);
	~Stack();
	void push(Shape&);
	Shape pop();
	int getSize();
private:

};

Stack::Stack(int size)
{
	this->tos = 0;
	this->size = size;
	this->stk = new Shape*[size];


}

Stack::~Stack()
{
	delete* stk;
}

Shape Stack::pop() {
	if (tos==0)
	{
		cout << "\nstack is empty"<<endl;
	}
	else {
		tos--;
		Shape s = *stk[tos];
		if (&s != NULL)
		{
			return s;
		}
	}
	return Shape("null");
}

void Stack::push(Shape &n) {
	if (tos==this->size) {
		cout << "\nStack is full, can't add more values"<<endl;
	}
	else {
		stk[tos] = &n; tos++;
	}
}

int Stack::getSize() {
	return this->size;
}
int main() {

	int shapesSize = 4;
	Shape **shapes = new Shape*[4];
	shapes[0] = new Shape("Circle");
	shapes[1] = new Shape("Square");
	shapes[2] = new Shape("Quad");
	shapes[3] = new Shape("Cube");
	//cout <<"Number of instances of Shape: " <<Shape::getNoOFAllShapes() << endl;
	Stack stackOfShapes(6);
	stackOfShapes.push(*(new Shape("Ball")));
	stackOfShapes.push(*(new Shape("Sphere")));
	

	//cout << "Number of instances of Shape: " << Shape::getNoOFAllShapes() << endl;

	for (int i = 0; i < shapesSize; i++)
	{
		stackOfShapes.push(*(shapes[i]));
	}
	//cout << "Number of instances of Shape: " << Shape::getNoOFAllShapes() << endl;

	for (int i = 0; i < stackOfShapes.getSize(); i++)
	{
		stackOfShapes.pop().ToString();
	}
	//for (int i = 0; i < shapesSize; i++)
	//{
	//	delete shapes[i];
	//}
	cout << "Number of instances of Shape: " << Shape::getNoOFAllShapes() << endl;


}

