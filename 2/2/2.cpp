#include<iostream>

class smart_array {
	double re_, im_;
private:
	int once = 0;
	int size = 0;
	int* arr = new int[size];
public:
	smart_array& operator=(const smart_array& other) {
		re_ = other.re_;
		im_ = other.im_;
		return *this;
	}

	smart_array(int size) {
		this->size = size;
		this->arr = new int[size];
	}
	void add_element(int num) {
		if (once >= size) {
			throw "Массив полон";
		}
		else {
			arr[once] = num;
		}
		once++;
	}

	int get_element(int elem) {
		if (elem >= once) {
			throw "Нет элемента с таким индексом";
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

		smart_array new_array(2);
		new_array.add_element(44);
		new_array.add_element(34);

		arr = new_array;
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}
	return 0;
}