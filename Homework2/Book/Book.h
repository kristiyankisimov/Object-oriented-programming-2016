#ifndef BOOK_H_
#define BOOK_H_

class Book {
public:
	Book(const char* = "", const char* = "", double = 0.0, int = 0);
	Book(const Book&);
	Book& operator=(const Book&);
	~Book();
	void setName(const char*);
	void setAuthor(const char*);
	void setPrice(double);
	void setCode(int);
	void read();
	const char* getName() const;
	const char* getAuthor() const;
	double getPrice() const;
	int getCode() const;
	void print() const;
private:
	char* name;
	char* author;
	double price;
	int code;

	void copy(const char*, const char*, double, int);
	void del();
};

#endif /* BOOK_H_ */
