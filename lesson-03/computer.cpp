#include <iostream>
#include <optional>
#include <utility>
#include <vector>

class Computer {
private:
	std::string brand;
	std::string fault;
public:
	Computer DefineComputer(std::string newBrand, std::string newFault) {
		this->brand = move(newBrand);
		this->fault = move(newFault);
		return *this;
	}
	std::string CurrentBrand() {
		return this->brand;
	}
	std::string CurrentFault() {
		return this->fault;
	}
};

class ITSpecialist {
private:
	std::string name;
	std::optional<std::vector<Computer>> repairedMachine;
public:
	void NameSpecialist(std::string SpecialistsNewName) {
		this->name = std::move(SpecialistsNewName);
	}
	void RepairComputer(const Computer& computer) {
		this->repairedMachine->push_back(computer);
	}
}; 

int main()
{
	Computer computer;
	ITSpecialist itspecialist;
	std::cout << "computer was repaired by";
	std::cout << itspecialist;
	return 0;
}
