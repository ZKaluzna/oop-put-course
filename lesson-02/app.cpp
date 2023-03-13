#include <string>
#include <iostream>

using namespace std;

class cat {
public:
	int age;
	string color;
	string size;
};

class bike {
public:
	string brand;
	string color;
	int sizeoftires;
};

int main()
{
	bike monocycle;
	cat mruczek;
	mruczek.size = "chunky";
	mruczek.age = 21;
	monocycle.sizeoftires = 37;

    std::cout << mruczek.size<<endl;
	std::cout << mruczek.age;
	std::cout << monocycle.sizeoftires;
}
