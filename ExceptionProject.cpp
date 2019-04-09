#include <iostream>
#include <string>

class InvalidEmployeeNumber : public std::exception {
	const char * msg;
	InvalidEmployeeNumber() {};    // no default constructor 
public:
	//explicit means argument value must be assigned with constructor only!  
	//exception specification  
	//throw() means that if an exception is thrown call std::unexpected   
	explicit InvalidEmployeeNumber(const char * s) throw() : msg(s) { }
	virtual const char * what() const throw() { return msg; }
};

class InvalidShift : public std::exception {
	const char * msg;
	InvalidShift() {};    // no default constructor 
public:
	//explicit means argument value must be assigned with constructor only!  
	//exception specification  
	//throw() means that if an exception is thrown call std::unexpected   
	explicit InvalidShift(const char * s) throw() : msg(s) { }
	virtual const char * what() const throw() { return msg; }
};

class InvalidPayRate : public std::exception {
	const char * msg;
	InvalidPayRate() {};    // no default constructor 
public:
	//explicit means argument value must be assigned with constructor only!  
	//exception specification  
	//throw() means that if an exception is thrown call std::unexpected   
	explicit InvalidPayRate(const char * s) throw() : msg(s) { }
	virtual const char * what() const throw() { return msg; }
};


class Employee {
	std::string _name;
	int _number;
	std::string _hireDate;
	Employee() {};
protected:
	Employee(std::string name, int number, std::string hireDate) {
		if (number < 0 || number > 9999) {
			throw InvalidEmployeeNumber("Invalid Employee Number");
		}else {
			_name = name;
			_number = number;
			_hireDate = hireDate;
		}
	};
public:
	std::string & name() { return _name; }
	int number() { return _number; }
	std::string & hireDate() { return _hireDate; }
};

class ProductionWorker : public Employee {
	int _shift;
	double _hourlyPayRate;
public:
	ProductionWorker(int shift, double rate, std::string name, int number, std::string hireDate) : Employee(name, number, hireDate) {
		if (shift < 1 || shift > 2) {
			throw InvalidShift("Invalid Shift");
		}else if (rate < 0) {
			throw InvalidPayRate("Invalid Pay Rate");
		}else {
			_shift = shift;
			_hourlyPayRate = rate;
		}
	};
	int shift() { return _shift; }
	double hourlyPayRate() { return _hourlyPayRate; }
	void changeShift() {
		if (_shift == 1) {
			_shift = 2;
		}
		else {
			_shift = 1;
		}
	}
};

int main() {
	//This should throw the InvalidEmployeeNumber class
	try {
		ProductionWorker p1(1, 23, "John Doe", 10000, "4/11/15");
	}
	catch (InvalidEmployeeNumber & e) {
		std::cout << "Constructing error: " << e.what() << std::endl;
	}
	
	//This should throw the InvalidShift class
	try {
		ProductionWorker p2(0, 23, "John Doe", 2345, "4/11/15");
	}
	catch (InvalidShift & e) {
		std::cout << "Constructing error: " << e.what() << std::endl;
	}

	//This should throw the InvalidPayRate class
	try {
		ProductionWorker p3(2, -5, "John Doe", 1000, "4/11/15");
	}
	catch (InvalidPayRate & e) {
		std::cout << "Constructing error: " << e.what() << std::endl;
	}	

	return 0;
}