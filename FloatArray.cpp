#include <iostream>

using namespace std;

class FloatArray {
private:
	int size;
	float *array;
public:
	//Constructor
	FloatArray(int size){
		this->size = size;
		array = new float[size]; 
	}

	//Deconstructor
	~FloatArray(){
		delete [] array;  
		array = NULL;
	}

	//Member Functions
	void storeValue(float value, int index) {
		array[index] = value;
	}

	float getValue(int index) {
		return array[index];
	}

	float getHighestValue() {
		float highest = array[0];
		for (int x = 1; x < size; x++) {
			if (array[x] > highest) {
				highest = array[x];
			}
		}
		return highest;
	}

	float getLowestValue() {
		float lowest = array[0];
		for (int x = 1; x < size; x++) {
			if (array[x] < lowest) {
				lowest = array[x];
			}
		}
		return lowest;
	}

	int getSize() {
		return size;
	}
};

int main() {
	FloatArray arr(5);
	arr.storeValue(1.5, 0);
	arr.storeValue(11, 1);
	arr.storeValue(23, 2);
	arr.storeValue(0.45, 3);
	arr.storeValue(0.99, 4);
	
	cout << arr.getValue(3) << endl;
	cout << arr.getHighestValue() << endl;
	cout << arr.getLowestValue() << endl;

	arr.~FloatArray;

}