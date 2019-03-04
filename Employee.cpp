#include <iostream> 
#include <string>

using namespace std;

class Employee {
private:
	string name;
	int idnumber;
	string department;
	string position;

public:
	Employee(string n, int i, string d, string p) {
		name = n;
		idnumber = i;
		department = d;
		position = p;
	};

	Employee(string n, int i) {
		name = n;
		idnumber = i;
		department = "";
		position = "";
	};
	
	Employee() {
		name = "";
		idnumber = 0;
		department = "";
		position = "";
	};

	string getName() {return name;}
	int getIDNumber() {return idnumber;}
	string getDepartment() {return department;}
	string getPosition() {return position;}

	void setName(string n) { name = n; }
	void setIDNumber(int i) { idnumber = i; }
	void setDepartment(string d) { department = d; }
	void setPosition(string p) { position = p; }
};

int main(void) {
	
	Employee Employee1("Susan Meyers", 47899, "Accounting", "Vice President");
	Employee Employee2("Mark Jones", 39119,"IT", "Programmer");
	Employee Employee3("Joy Rogers", 81774, "Manufacturing", "Engineer");

	cout << "Name		ID Number	Department        Position" << endl;
	cout << Employee1.getName() << "    " << Employee1.getIDNumber() << "		" << Employee1.getDepartment() << "        " << Employee1.getPosition() << endl;
	cout << Employee2.getName() << "      " << Employee2.getIDNumber() << "		" << Employee2.getDepartment() << "		  " << Employee2.getPosition() << endl;
	cout << Employee3.getName() << "      " << Employee3.getIDNumber() << "		" << Employee3.getDepartment() << "     " << Employee3.getPosition() << endl;

	return 0;
}
