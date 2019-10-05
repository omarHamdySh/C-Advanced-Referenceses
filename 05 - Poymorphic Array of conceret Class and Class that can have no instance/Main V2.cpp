// TestProject2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Animal {

public:
	virtual void makeSound() { cout << "The animal says grr" << endl; };
};

class Dog : public Animal {

public :
	 void makeSound() { cout << "The animal says woof" << endl; };

};

class Cat : public Animal {
	
public :
	void makeSound() { cout << "The animal says meow" << endl; };

};

class Car {
public:
	virtual int getNumWheels() = 0;
	virtual int getNumDoors() = 0;
};

class StationWagon {
public:
	int getNumWheels() { cout << "StationWagon has four wheels" << endl;  return 4; };
	int getNumDoors() { cout << "Station wagons has four doors" << endl; return 4; };
	StationWagon() {};
	~StationWagon() {};
};
void funcPtr(Animal* p)
{
	std::cout << "Length of array = " << (sizeof(p) / sizeof(*p)) << std::endl;
}
void funcPtrPtr(Animal** p)
{
	std::cout << "Length of array = " << (sizeof(p) / sizeof(Animal)) << std::endl;
	
}


int main()
{
	Animal* ptrCat = new Cat();
	Animal* ptrDog = new Dog();

	ptrCat->makeSound();
	ptrDog->makeSound();
	Animal* animalsArr[4];
	animalsArr[0] = new Cat();
	animalsArr[1] = new Dog();
	animalsArr[2] = new Dog();
	animalsArr[3] = new Dog();

	for (int i = 0; i < 3; i++)
	{
		Animal *temp = animalsArr[i]; //makeSound();
		temp->makeSound();
	}

	//The car class can't be instantiated.
	//Car c = new Car(); //This line of code will give error if un commented
	StationWagon sw;
	sw.getNumWheels();
	sw.getNumDoors();
	return 0;
}
