#include<iostream>

class smart_array {
private:
	int once = 0;
	int size = 0;
	int* arr = new int[size];
public:
	smart_array(int size) {
		this->size = size;
		this->arr = new int[size];
	}
	void add_element(int num) {
		if (once >= size) {
			std::cout << "Массив полон" << std::endl;
		}
		else {
			arr[once] = num;
		}
		once++;
	}

	int get_element(int elem) {
		if (elem >= size) {
			std::cout << "Нет элемента с индексом: ";
			return elem;
		}
		else {
			return arr[elem];
		}
		
	}

	~smart_array() {
		delete[] arr;
	}
};
int main() {
	setlocale(LC_ALL, "Russian");

	try {
		smart_array arr(5);
		arr.add_element(1);
		arr.add_element(4);
		arr.add_element(155);
		arr.add_element(14);
		arr.add_element(15);
		std::cout << arr.get_element(1) << std::endl;
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}
	return 0;
}