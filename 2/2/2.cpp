#include<iostream>

#include<iostream>
#include<execution>

class smart_array {
private:
	int once = 0;
	int size = 0;
	int* arr = 0;
public:
	smart_array(int size) {
		this->size = size;
		this->arr = new int[size];
	}
	void add_element(int num) {
		if (once >= size) {
			throw std::domain_error("Массив полон");
		}
		else {
			arr[once] = num;
		}
		once++;
	}

	int get_element(int elem) {
		if (elem >= once || elem < 0) {
			throw std::out_of_range("Нет элемента с таким индексом");
			return elem;
		}
		else {
			return arr[elem];
		}

	}

	smart_array(const smart_array& other) {
		size = other.size;
		once = other.once;
		arr = new int[other.size];
		for (int i = 0; i < other.size; ++i) {
			arr[i] = other.arr[i];
		}
	}

	smart_array& operator=(const smart_array& other) {
		if (&other != this) {
			size = other.size;
			once = other.once;
			arr = new int[other.size];
			for (int i = 0; i < other.size; ++i) {
				arr[i] = other.arr[i];
			}
			return *this;
		}
		else {
			return *this;
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