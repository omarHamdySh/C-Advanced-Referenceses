#include <iostream>
//#include "Animal.cpp"
#include "Cat.h" 
//#include "Dog.h" 
using namespace std;

/*
If we have got a pointer of a class and that pointer holds the address to a variable of 
a child class of it, then the pointer will have the child class type and no up casting already happened

*/
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
	Cat cat("Cat parent");

	//Casting the pointer of the cat (The address) to be represented by an Animal pointer.
	Animal animal = cat;			//Refernce Up casting, Implicit Up casting the refernce of Cat to its Parent type Animal.

	//Casting the pointer of the Animal type to a pointer of its child type Cat
	Cat* cat2 = (Cat*)&animal;		//Pointer Down Casting, Just creating the 

	animal.saySomething();	//Animal type;
	cat2->saySomething();	//Cat type;


	cout << "---------------------------";
	Cat c("Cat parent");

	//Casting the pointer of the cat (The address) to be represented by an Animal pointer.
	Animal* a = &c;			//Implicit Pointer Up casting, Just using the pointer of the type parent to refer to the child

	//Casting the pointer of the Animal type to a pointer of its child type Cat
	Cat* c2 = (Cat*)a;		//Pointer Down Casting, Just creating the 

	(a)->saySomething();	//Cat type;

	Cat* c3;

	(c3 = (Cat*)a)->saySomething(); //Cat type		//Down Casting

	((Cat*)a)->saySomething(); //Cat type			//Down Casting

	c.saySomething(); //Cat type

	//animal[2] = dog::Dog("I am the parent of the Dog.");
}