#include <iostream>
#include <string>
using namespace std;

class Shape {
public:
	virtual double area() const = 0;
	virtual double perimeter() const = 0;
};

class Rectangle : public Shape {
public:
	Rectangle(double width, double height) : width_(width), height_(height) {}

	double area() const override {
		return width_ * height_;
	}

	double perimeter() const override {
		return 2 * (width_ + height_);
	}

private:
	const double width_;
	const double height_;
};

int main() {
	Rectangle r(5, 3);
	std::cout << "Rectangle width: " << r.width_ << std::endl;
	std::cout << "Rectangle height: " << r.height_ << std::endl;
	std::cout << "Rectangle area: " << r.area() << std::endl;
	std::cout << "Rectangle perimeter: " << r.perimeter() << std::endl;
	return 0;
}
