#include <iostream>
#include <string>

template <typename T>       
T maximum(const T & a, const T & b) {
	return (a > b ? a : b);          
}

template <typename T>        
T minimum(const T & a, const T & b) {
	return (a < b ? a : b); 
}

int main() {
	int a = 7;
	int b = 9;
	
	double e = 4.3;
	double f = 8.2;

	std::string c = "Seven";
	std::string d = "nine";
	 
	std::cout << "The maximum is " << maximum<int>(a, b) << std::endl;
	std::cout << "The maximum is " << maximum<std::string>(c, d) << std::endl;
	std::cout << "The maximum is " << maximum<double>(e, f) << std::endl;

	std::cout << "The minimum is " << minimum<int>(a, b) << std::endl;
	std::cout << "The minimum is " << minimum<std::string>(c, d) << std::endl;
	std::cout << "The minimum is " << minimum<double>(e, f) << std::endl;

	return 0;
}