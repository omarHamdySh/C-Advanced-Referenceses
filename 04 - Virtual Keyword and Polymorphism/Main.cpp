// TestProject2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Animal {

public:
	Animal() {};
	void getFamily() { cout << "We are animals" << endl; }
	virtual void getClass() { cout << "I am an animal" << endl; }

};

class Dog : public Animal {

public:
	Dog() :Animal() {};
	void getClass() { cout << "I am a Dog" << endl; }
};

class GermanShepard : public Dog {

public:
	GermanShepard() :Dog() {};
	void getClass() { cout << "I am a German Shepard" << endl; }
	void getDerived() { cout << "I am a Animal and Dog" << endl; }

};

void whatClassAreYou(Animal* animal) {//Polymorphic method

#pragma region Virtual Keyword detailed description

	/*** -------------- Similar to dynamic and static binding in polymorphism in java -------------------
	* This method has no idea about the Animal class or the drived classes from it.
	* It will got resolve the invokation of the getClass() method from the Animal Class.
	* If there were a virtual before getClass() at the Animal class.
	* it will look at the type of the instance that is passed to it first and then look for an
	* Overriden method from it, if it does exist it will be used if it doesn't. Then the one at
	* The parent class will be used.
	*-----------------------------------------------------------------------------------------------------
	* If there were no virtual keyword before the getClass() method in the Animal class
	* No matter what type was the instance that is sent as a parameter the method getClass() of the
	* Animal class will be called every and each time this method -> whatClassAreYou() will be called;
	*-----------------------------------------------------------------------------------------------------
	* Not just when the virtual keyword is missing the Animal's getClass() will be invoked, there is another case
	* and it is very crucial and really hard to figure out unless you have a very deep experience
	***/
#pragma endregion

	animal->getClass();
}


int main()
{
	Animal a;
	Dog d;

	whatClassAreYou(&a);
	whatClassAreYou(&d);

	Dog dog;
	GermanShepard germanDog;

	Animal* ptrDog = &dog; //Implicit Pointer Up casting, Just using the pointer of the type parent to refer to the child

	Animal* ptrGermanDog = &germanDog; //Implicit Pointer Up casting, Just using the pointer of the type grand parent to refer to the grand child


	ptrDog->getFamily();
	ptrDog->getClass();

	ptrGermanDog->getFamily();
	ptrGermanDog->getClass();

	//The following shows that there are no method called getDerived() in the class Animal the ptr has to be casted first.
	//ptrGermanDog->getDerived();  //If you removed the comment it will give an error.
	
	//Casting ptr from Animal type to GermanShepard type.
	GermanShepard* ptrNativeGerman = (GermanShepard*)ptrGermanDog;
	
	ptrNativeGerman->getDerived();  //If you removed the comment it will give an error.



}
