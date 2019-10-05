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


int main()
{
	Animal* ptrCat = new Cat();
	Animal* ptrDog = new Dog();

	ptrCat->makeSound();
	ptrDog->makeSound();

	Animal* animalsArr[2];
	animalsArr[0] = new Cat();
	animalsArr[1] = new Dog();

	for (int i = 0; i <= sizeof(**animalsArr) / sizeof(Animal); i++)
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
