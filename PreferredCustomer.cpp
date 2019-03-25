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

class PreferredCustomer : public CustomerData {
	double purchasesAmount;
	double discountLevel;
public:
	PreferredCustomer(double purchases, int number, bool list, std::string first, std::string last, std::string a, std::string c, std::string s, int z, std::string p) : CustomerData(number,list,first,last,a,c,s,z,p) {
		purchasesAmount = purchases;
		std::cout << "Initial Total Purchase Amount: " << "$" << purchasesAmount << std::endl;
		updateDiscountLevel();
	};
	void makePurchase(double purchase) {
		purchasesAmount += purchase;
		std::cout << "Total Purchase Amount: " << "$" << purchasesAmount << std::endl;
		updateDiscountLevel();
	}
	void updateDiscountLevel() {
		if (purchasesAmount >= 2000) {
			discountLevel = 0.10;
		}
		else if (purchasesAmount >= 1500){
			discountLevel = 0.07;
		}
		else if (purchasesAmount >= 1000) {
			discountLevel = 0.06;
		}
		else if (purchasesAmount >= 500) {
			discountLevel = 0.05;
		}
		else {
			discountLevel = 0.00;
		}
	}
	double discount() {
		return (discountLevel * 100);
	}
};

int main() {

	PreferredCustomer customer1(550, 1234, true, "Ryan", "Guidry", "1234 Long st.", "Brea", "California", 92821, "9099679799");
	
	std::cout << "---Customer 1---" << std::endl;
	std::cout << "Discount: " << customer1.discount() << "%" << std::endl;
	customer1.makePurchase(900);
	std::cout << "Discount: " << customer1.discount() << "%" << std::endl;

	PreferredCustomer customer2(1438, 1001, false, "Ethan", "Allen", "4321 Short st.", "Fullerton", "California", 92832, "7143100206");

	std::cout << "---Customer 2---" << std::endl;
	std::cout << "Discount: " << customer1.discount() << "%" << std::endl;
	customer1.makePurchase(900);
	std::cout << "Discount: " << customer1.discount() << "%" << std::endl;
	
	return 0;
}
