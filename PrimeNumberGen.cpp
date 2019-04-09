#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	std::vector<int> primes;

	int num;
	int isPrime;
	bool valid = false;
	while (!valid) {
		std::cout << "Enter an integer greater than 1: ";
		std::cin >> num;
		if (num > 1) valid = true;
		else std::cout << "Invalid number. Try Again." << std::endl;
	}
	for (int x = 2; x <= num; x++) {
		isPrime = 0;
		for (int y = 2; y <= x / 2; y++) {
			if (x%y == 0) {
				isPrime = 1;
				break;
			}
		}
		if (isPrime == 0) {
			primes.push_back(x);
		}
	}

	std::cout << "Prime Numbers up to " << num << " are:";

	//Using the STL's for_each function to step through the vector primes
	auto print = [](const int& n) { std::cout << " " << n; };
	std::for_each(primes.begin(), primes.end(), print);

	return 0;
}