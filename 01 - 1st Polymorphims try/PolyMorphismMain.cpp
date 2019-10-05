#include <iostream>
//#include "Animal.cpp"
#include "Cat.h" 
//#include "Dog.h" 
using namespace std;
int main()
{
	//------------------------------------------ Polymorphism ------------------------------------------
	//-------------------------------------Up Casting & down Casting------------------------------------

	//Note: with up casting the constructor of the parent will not be called
	//Note: with down casting the destructor of the parent will be called at the casting process

	Animal animals[1];
	*animals = Cat("1st cat"); //Accessing the first address in the array by derefrencing the array pointer.
	((Cat*)animals)->saySomething(); //Actually the casting with pointer it is creating anonymous pointer that it can be used only at this line of coed.

	animals[0] = Cat("2nd cat"); //Accessing the firs address in the array by index.
	((Cat*)&animals[0])->saySomething();

	cout << "---------------------------";
	Cat c("Cat parent");

	Animal* a = &c;			//Up Casting

	Cat* c2 = (Cat*)a;		//Down Casting

	(a)->saySomething();	//Animal Type;

	Cat* c3;

	(c3 = (Cat*)a)->saySomething(); //Cat type		//Down Casting

	((Cat*)a)->saySomething(); //Cat type			//Down Casting

	c.saySomething(); //Cat type

	//animal[2] = dog::Dog("I am the parent of the Dog.");
}