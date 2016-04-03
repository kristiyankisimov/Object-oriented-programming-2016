#include "List.h"

#include <iostream>
#include <cstdlib>

using namespace std;

const int INITIAL_CAPACITY = 20;

void List::copy(int* _arr, int _size, int _cap) {
	size = _size;
	cap = _cap;

	arr = new int[cap];
	if (arr != NULL) {
		for (int i = 0; i < size; i++) {
			arr[i] = _arr[i];
		}
	}
}

void List::del() {
	if (arr != NULL) {
		delete[] arr;
	}
}

List::List() {
	copy(NULL, 0, INITIAL_CAPACITY);
}

List::List(int _cap) {
	copy(NULL, 0, _cap);
}

List::List(const List& other) {
	copy(other.arr, other.size, other.cap);
}

List::List(int* arr, int size) {
	copy(arr, size, size * 2);
}

List& List::operator=(const List& other) {
	if (this != &other) {
		del();
		copy(other.arr, other.size, other.cap);
	}
	return *this;
}

List::~List() {
	del();
}

int List::operator[](int i) {
	if (i > 0 && i < size) {
		return arr[i];
	}
	exit(1);
}

List List::operator+(const List& other) {
	List list = List(*this);
	list.print();
	list += List(other);
	list.print();
	return list;
}

void List::operator+=(const List& other) {
	resize(size);
	for (int i = 0; i < other.size; i++) {
		addElement(other.arr[i]);
	}
}

bool List::isEmpty() const {
	return size == 0 || arr == NULL;
}

void List::addElement(int el) {
	if (size == cap) {
		resize();
	}
	arr[size] = el;
	size++;
}

int List::getSize() const {
	return size;
}

void List::removeElement(int index) {
	if (index < 0 || index >= size) {
		exit(1);
	}

	for (int i = index; i < size - 1; i++) {
		arr[i] = arr[i + 1];
	}
	size--;
}

void List::print() {
	cout << "[";
	for (int i = 0; i < size - 1; i++) {
		cout << arr[i] << ", ";
	}
	cout << arr[size - 1];
	cout << "]\n";
}

void List::resize(int new_cap) {
	int* buf = arr;

	cap = cap + new_cap;
	arr = new int[cap];
	for (int i = 0; i < size; i++) {
		arr[i] = buf[i];
	}

	delete[] buf;
}

void List::resize() {
	resize(cap);
}

void List::removeAllEqualsTo(int value) {
	if (containsElement(value)) {
		int k = 0;
		int* help_arr = new int[cap];
		for (int i = 0; i < size; i++) {
			if (arr[i] != value) {
				help_arr[k] = arr[i];
				k++;
			}
		}
		size = k;
		del();
		arr = help_arr;
	}
}

bool List::containsElement(int value) {
	for (int i = 0; i < size; i++) {
		if (arr[i] == value) {
			return true;
		}
	}
	return false;
}

int List::occurrences(int value) {
	int count = 0;
	for (int i = 0; i < size; i++) {
		if (arr[i] == value) {
			count++;
		}
	}
	return count;
}

void List::sort(int type) {
	for (int i = 0; i < size - 1; i++) {
		int k = i;
		int optimum = arr[i];
		for (int j = i + 1; j < size; j++) {
			if (type == 1) {
				if (arr[j] < optimum) {
					optimum = arr[j];
					k = j;
				}
			} else if (type == 2) {
				if (arr[j] > optimum) {
					optimum = arr[j];
					k = j;
				}
			}

		}
		if (k != i) {
			swap(arr[i], arr[k]);
		}
	}
}
