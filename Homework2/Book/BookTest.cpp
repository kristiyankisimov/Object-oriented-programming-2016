#include <iostream>
#include <cstring>
#include "Book.h"

using namespace std;

void sort(Book** pBooksArray, int booksCount) {
	for (int i = 0; i < booksCount - 1; i++) {
		int k = i;
		Book* min = pBooksArray[i];
		for (int j = i + 1; j < booksCount; j++) {
			if (pBooksArray[j]->getCode() < min->getCode()) {
				min = pBooksArray[j];
				k = j;
			}
		}
		if (i != k) {
			min = pBooksArray[i];
			pBooksArray[i] = pBooksArray[k];
			pBooksArray[k] = min;
		}
	}
}

Book* findByCode(int code, Book* booksArray, int booksCount) {
	for (int i = 0; i < booksCount; i++) {
		if (booksArray[i].getCode() == code) {
			return &booksArray[i];
		}
	}
	return NULL;
}

int getBooksByAuthor(char* authorName, Book** filteredBooks, Book* booksArray,
		int booksCount) {
	int k = 0;
	for (int i = 0; i < booksCount; i++) {
		if (strcmp(authorName, booksArray[i].getAuthor()) == 0) {
			filteredBooks[k] = &booksArray[i];
			k++;
		}
	}
	return k;
}

void printBooksArray(Book** books, int booksCount) {
	for (int i = 0; i < booksCount; i++) {
		books[i]->print();
		cout << endl;
	}
}


int main() {
	int booksCount;
	cout << "Enter number of books: ";
	cin >> booksCount;

	Book* books = new Book[booksCount];
	Book** pBook = new Book*[booksCount];

	for (int i = 0; i < booksCount; i++) {
		books[i].read();
		pBook[i] = &books[i];
	}

	double price;
	cout << "Enter price for filter:";
	cin >> price;
	cout << "\nBooks with price > " << price << "\n\n";
	for (int i = 0; i < booksCount; i++) {
		if (books[i].getPrice() >= price) {
			books[i].print();
			cout << endl;
		}
	}

	cout << "\nSorted books:\n\n";
	sort(pBook, booksCount);
	for (int i = 0; i < booksCount; i++) {
		pBook[i]->print();
		cout << endl;
	}

	char authorName[128];
	cin.get();
	cout << "Enter author name: ";
	cin.getline(authorName, 128);

	Book** filteredBookArray = new Book*[booksCount];
	int filteredBooksCount = getBooksByAuthor(authorName, filteredBookArray, books,
			booksCount);
	if (filteredBooksCount > 0) {
		cout << "Books with author " << authorName << ": ";
		printBooksArray(filteredBookArray, filteredBooksCount);
	} else {
		cout << "There is no books written by " << authorName << endl;
	}

	int code;
	cout << "Enter code for search:";
	cin >> code;

	Book* b = findByCode(code, books, booksCount);
	b->print();

	delete [] books;
	delete [] pBook;
	delete [] filteredBookArray;

	return 0;
}

