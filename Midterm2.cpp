#include <iostream>
#include <string>
#include <vector>

class Human {
private:
	std::string _name;
	int age;
	char sex;
	Human() {};
protected:
	Human(std::string n, int a, char s) {
		_name = n;
		age = a;
		sex = s;
	};

	virtual ~Human() {

	};
public:
	std::string getName() { return _name; }
	int getAge() { return age; }
	char getSex() { return sex; }
};

class Child : public Human {
private:
	std::string _momName;
	std::string _dadName;
	int allowance;
	//Child() {};
public:
	Child(std::string name, int age, char sex, std::string mName, std::string dName) : Human(name, age, sex) {
		_momName = mName;
		_dadName = dName;
		allowance = 0;
	}
	int getAllowance() const { return allowance; }
	void printParent() {
		std::cout << "Mother: " << _momName << std::endl;
		std::cout << "Father: " << _dadName << std::endl;
	}
	friend class Parent;
};

class Parent : public Human {
private:
	std::vector<std::string> children;
	//Parent(){};
public:
	Parent(std::string name, int age, char sex) : Human(name, age, sex) {
	};
	void printChild() {
		for (int i = 0; i < children.size(); i++) {
			std::cout << children[i] << std::endl;
		}	
	}
	void setChild(Child c) {
		children.push_back(c.getName());
	}
	void setChildAllowance(int allowance, Child c) {
		for (int i = 0; i < children.size(); i++) {
			if (c.getName().compare(children[i]) == true) {
				c.allowance = allowance;
			}
		}
	}
};

void printInfo(Human& h) {
	std::cout << "Name: " << h.getName() << std::endl;
	std::cout << "Age: " << h.getAge() << std::endl;
	std::cout << "Sex: " << h.getSex() << std::endl;
}

int main() {
	Parent homer("Homer", 36, 'M');
	Parent march("March", 34, 'F');
	Child lisa("Lisa", 12, 'F', "March", "Homer");
	Child bart("Bart", 10, 'M', "March", "Homer");
	Child maggie("Maggie", 3, 'F', "March", "Homer");
	homer.setChild(lisa);
	homer.setChild(bart);
	homer.setChild(maggie);
	march.setChild(lisa);
	march.setChild(bart);
	march.setChild(maggie);

	std::cout << "Bart's Allowance: " << bart.getAllowance() << std::endl;
	homer.setChildAllowance(5,bart);
	std::cout << "Bart's Allowance: " << bart.getAllowance() << std::endl;
	bart.printParent();
	printInfo(march);
	printInfo(lisa);

}

