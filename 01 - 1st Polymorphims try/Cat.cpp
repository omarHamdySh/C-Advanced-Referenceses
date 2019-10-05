#include "Cat.h"

Cat::Cat():Animal()
{
}

Cat::Cat(string str): Animal(str)
{
	std::cout << str<<endl;
}

void Cat::saySomething()
{
	cout << "Hi I am a cat"<<endl;
}
