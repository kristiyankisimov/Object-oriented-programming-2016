#ifndef LIST_H_
#define LIST_H_

class List {
public:
	List();
	List(int);
	List(const List&);
	List(int*, int);

	List& operator=(const List&);
	~List();

	int operator[](int);
	List operator+(const List&);
	void operator+=(const List&);

	int getSize() const;
	bool isEmpty() const;
	void addElement(int);
	void removeElement(int);
	void removeAllEqualsTo(int);

	bool containsElement(int);
	int occurrences(int);

	void sort(int);

	void print();

private:
	int* arr;
	int size;
	int cap;

	void resize(int);
	void resize();

	void copy(int*, int, int);
	void del();
};

#endif /* LIST_H_ */
