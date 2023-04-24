#include <sstream>
#include <iostream>
#include <memory>
#include <cassert>

class Sequence {
public:
	virtual int Length() = 0;
	class Fake;
};


class Sequence::Fake : public Sequence {
	int Length() { return 100; }
};

class Gene {
private:
	std::string name_;
	std::shared_ptr<Sequence> sequence_;
public:
	Gene(std::string name, std::shared_ptr<Sequence> sequence)
		: name_(name), sequence_(sequence) {};
	std::string JSON() {
		std::stringstream ss;
		ss << "{";
		ss << " \"name\": \"" << name_ << "\",";
		ss << " \"length\": " << sequence_->Length();
		ss << "}";
		return ss.str();
	}
};


int main()
{
	std::shared_ptr<Sequence> fakeSequence = std::make_shared<Sequence::Fake>();
	Gene gene("BALF5", fakeSequence);
	std::cout << gene.JSON();
	assert(fakeSequence->Lenght()==100);
	return 0;
}
