#include <iostream>
#include <string>

class PersonData
{
	std::string _lastName;
	std::string _firstName;
	std::string _address;
	std::string _city;
	std::string _state;
	int _zip;
	std::string _phone;
	PersonData() {};
protected:
	PersonData(std::string last, std::string first, std::string a, std::string c, std::string s, int z, std::string p) {
		_lastName = last;
		_firstName = first;
		_address = a;
		_city = c;
		_state = s;
		_zip = z;
		_phone = p;
	};
public:
	std::string & lastName() { return _lastName; }
	std::string & firstName() { return _firstName; }
	std::string & address() { return _address; }
	std::string & city() { return _city; }
	std::string & state() { return _state; }
	int zip() { return _zip; }
	std::string phone() { return _phone; }
};

class CustomerData : public PersonData
{
	int customerNumber;
	bool mailingList;
public:
	CustomerData(int number, bool list, std::string first, std::string last, std::string a, std::string c, std::string s, int z, std::string p) : PersonData(last, first, a, c, s, z, p) {
		customerNumber = number;
		mailingList = list;
	};
	int number() { return customerNumber; }
	void checkMailingList() {
		if (mailingList) {
			std::cout << "You are on the Mailing List" << std::endl;
		}
		else {
			std::cout << "You are not on the Mailing list" << std::endl;
		}
	}
};

int main() {

	CustomerData customer1(1234,true, "Ryan", "Guidry", "1234 Long st.", "Brea", "California", 92821, "9099679799");
	CustomerData customer2(1001, false, "Ethan", "Allen", "4321 Short st.", "Fullerton", "California", 92832, "7143100206");

	std::cout << "---Customer Data---" << std::endl;
	std::cout << "Name: " << customer1.firstName() << " " << customer1.lastName() << std::endl;
	std::cout << "Address: " << customer1.address() << ", " << customer1.city() << ", " << customer1.state() << std::endl;
	std::cout << "Zip: " << customer1.zip() << std::endl;
	std::cout << "Phone: " << customer1.phone() << std::endl;
	std::cout << "Customer Number: " << customer1.number() << std::endl;
	customer1.checkMailingList();

	std::cout << "---Customer Data---" << std::endl;
	std::cout << "Name: " << customer2.firstName() << " " << customer2.lastName() << std::endl;
	std::cout << "Address: " << customer2.address() << ", " << customer2.city() << ", " << customer2.state() << std::endl;
	std::cout << "Zip: " << customer2.zip() << std::endl;
	std::cout << "Phone: " << customer2.phone() << std::endl;
	std::cout << "Customer Number: " << customer2.number() << std::endl;
	customer2.checkMailingList();


	return 0;
}