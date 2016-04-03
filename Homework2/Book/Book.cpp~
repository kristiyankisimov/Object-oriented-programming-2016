#include "Book.h"

#include <iostream>
#include<cassert>
#include<cstring>
using namespace std;

const int CODE_MAX = 99999;
const int CODE_MIN = 10000;

void Book::del() {
	if (this->name != NULL) {
		delete[] this->name;
	}
	if (this->author != NULL) {
		delete[] this->author;
	}
}

void Book::copy(const char* _name, const char* _author, double _price,
		int _code) {
	this->setName(_name);
	this->setAuthor(_author);
	this->setPrice(_price);
	this->setCode(_code);
}

Book::Book(const char* _name, const char* _author, double _price, int _code) {
	this->copy(_name, _author, _price, _code);
}

Book::Book(const Book& other) {
	this->copy(other.name, other.author, other.price, other.code);
}

Book& Book::operator=(const Book& _other) {
	if (this != &_other) {
		this->del();
		this->copy(_other.name, _other.author, _other.price, _other.code);
	}
	return *this;
}

Book::~Book() {
	this->del();
}
void Book::setName(const char* _name) {
	if (_name != NULL) {
		delete[] this->name;
		this->name = new char[strlen(_name) + 1];
		// checks whether memory is allocated successfully
		assert(this->name != NULL);
		strcpy(this->name, _name);
	}
}
void Book::setAuthor(const char* _author) {
	if (_author != NULL) {
		delete[] this->author;
		this->author = new char[strlen(_author) + 1];
		assert(this->author != NULL);
		strcpy(this->author, _author);
	}
}
void Book::setPrice(double _price) {
	this->price = _price;
}
void Book::setCode(int _code) {
	if (_code >= CODE_MIN && _code <= CODE_MAX) {
		this->code = _code;
	} else {
		this->code = 0;
	}
}
const char* Book::getName() const {
	return name;
}
const char* Book::getAuthor() const {
	return author;
}
double Book::getPrice() const {
	return price;
}
int Book::getCode() const {
	return code;
}
void Book::print() const {
	cout << "Book[Name: " << name << " " << "Author: " << author << " "
			<< "Price: " << price << " " << "Code: " << code << "]" << endl;
}
void Book::read() {
	char buffer[1024];

	cin.get();
	cout << "Enter name: ";
	cin.getline(buffer, 1024);
	this->setName(buffer);

	cout << "Enter author: ";
	cin.getline(buffer, 1024);
	this->setAuthor(buffer);

	double _price;
	do {
		cout << "Enter price: ";
		cin >> _price;
	} while (_price <= 0);
	this->setPrice(_price);

	int _code;
	do {
		cout << "Enter code: ";
		cin >> _code;
	} while (_code < CODE_MIN || _code > CODE_MAX);
	this->setCode(_code);
}
