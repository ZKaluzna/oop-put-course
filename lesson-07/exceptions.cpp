#include <iostream>
#include <cmath>
#include <stdexcept>

class Logarithm {
public:
	Logarithm(double base, double number) {
		base_ = base;
		number_ = number;
	}

	double Calculate() const {
		if (number_ <= 0) {
			throw std::invalid_argument("Number must be greater than 0.");
		}
    if (base_ <= 0 || base_ == 1) {
			throw std::invalid_argument("Base must be greater than 0 and not equal to 1.");
		}
		return std::log(number_) / std::log(base_);
	}

private:
	double base_;
	double number_;
};

int main() {
	double base, number;
	std::cout << "Enter the base: ";
	std::cin >> base;
	std::cout << "Enter the number: ";
	std::cin >> number;

	try {
		Logarithm log(base, number);
		double result = log.Calculate();
		std::cout << "Logarithm result: " << result << std::endl;
	}
	catch (const std::invalid_argument & e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}
