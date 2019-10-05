#include "Dog.h"

Dog::Dog():Animal()
{
}

Dog::Dog(string str):Animal(str)
{
}

void Dog::saySomething()
{
	cout << "Hi, I am a dog." << endl;
}
