//------------------------ Stack of concrete type ---------------------
//-------------------------- Pointer to Pointer -----------------------

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
	cout << "\n------- Stack push and pop program start -------" << endl;
	Shape* x[4];
	x[0] =  new Shape("Square");
	x[1] =	new Shape("Square");
	x[2] =	new Shape("Square");
	x[3] =	new Shape("Square");
	Stack s(6);
	s.push(*new Shape("Ball"));
	s.push(*new Shape("Cube"));
	try
	{
		for (int i = 0; i <= sizeof(**x)/sizeof(Shape) - 1; i++)
		{
			s.push(*x[i]);
		}

		for (int i = 0; i <= s.getSize() - 1; i++)
		{
			cout << s.pop().getName() << endl;
		}
	}
	catch (const std::exception& e)
	{
		cout << "Exception" << e.what() << endl;
	}
	

	cout << "Number of Shapes in memeory right now:" << Shape::getNoOFAllShapes() << endl;
	cout << "Size of stack in memeory" << sizeof(s) << endl;


}

