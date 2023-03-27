#include <string>
#include <iomanip>
#include <sstream>
#include <iostream>

class Drinks {
private:
 float gallons;
public:
    std::string fluids () {
    std::stringstream stream;
    stream << std::fixed << std::setprecision (0) << gallons;
    std::string s = stream.str ();
    return s;
}
 
    Drinks(float gallons) {
        this->gallons = gallons;
    } 
    Drinks(int gallons) : Drinks(static_cast<float>(gallons)){};

    
};

 
int 
main () 
{
Drinks morningDrinks (9.99f);
Drinks eveningDrinks (4);
std::cout << "He drunk " + eveningDrinks.fluids() +" gallons today. What a freak!";
return 0;
}
