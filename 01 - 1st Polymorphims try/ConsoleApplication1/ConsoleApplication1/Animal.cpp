#include "Animal.h"
Animal::Animal()
{
	cout << constructorsStrings<<endl;

}

Animal::Animal(string str):Animal()
{
	this->constructorsStrings = str;
}


Animal::~Animal()
{
	destructorsStrings= "Here is the cpp file destructor";
	cout << destructorsStrings<<endl;

}

string Animal::getConstructorStrings()
{
	return constructorsStrings;
}

string Animal::getDestructorStrings()
{
	return destructorsStrings;
}

void Animal::saySomething()
{
	cout << "Animal Says Hi"<<endl;
}





