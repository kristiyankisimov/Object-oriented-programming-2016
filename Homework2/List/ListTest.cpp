#include <iostream>
#include <iomanip>
#include "List.h"

using namespace std;
enum SortType {
	ASC = 1, DESC = 2
};
int main() {
	List list1;
	cout << boolalpha << list1.isEmpty() << endl;

	list1.addElement(2);
	list1.addElement(3);

	cout << "list1: ";
	list1.print();

	List list2 = List(list1);
	cout << "list2: ";
	list2.print();

	list2 += list1;
	cout << "list2: ";
	list2.print();

	List list3 = list2 + list1;
	cout << "list3: ";
	list3.print();

	list3.removeAllEqualsTo(1);
	list3.removeElement(0);
	cout << "list3: ";
	list3.print();

	int arr[] = { 6, 4, 5, -8, 4 };
	List list4(arr, 5);
	list4.print();

	cout << list4.occurrences(1) << endl;
	SortType type = DESC;
	list4.sort(type);
	cout << "Sorted ASC: "; list4.print();

	return 0;
}
