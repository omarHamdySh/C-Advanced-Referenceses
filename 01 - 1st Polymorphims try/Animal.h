#include <iostream>
using namespace std;
class Animal
{
public:
	string constructorsStrings;
	string destructorsStrings;
public:
	Animal();
	Animal(string str);
	~Animal();
	string getConstructorStrings();
	string getDestructorStrings();
	void saySomething();
	
};




