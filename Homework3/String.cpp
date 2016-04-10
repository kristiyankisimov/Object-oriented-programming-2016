#include <iostream> 
using namespace std;

class String {
	char* str;
	int len;
public:
	String()
	{
		str = new char[1];
		str[0] = '\0';
		len = 0;
	}

	String(const char* str)
	{
		len = strlen(str);
		this->str = new char[len + 1];
		strcpy(this->str, str);
	}

	String(const String& string)
	{
		len = string.length();
		str = new char[len + 1];
		strcpy(str, string.c_str());
	}

	~String()
	{
		delete [] str;
	}

	int length() const
	{
		return len;
	}

	const char* c_str() const
	{
		return str;
	}

	String& operator = (const String& string)
	{
		if (this != &string)
		{
			delete [] str;

			len = string.length();
			str = new char[len + 1];
			strcpy(str, string.c_str());
		}

		return *this;
	}

	String& operator=(const char* str)
	{
		String s(str);
		*this = s;
		return *this;
	}

	String operator+(const String& string)
	{
		char* newStr = new char[length() + string.length() + 1];
		strcpy(newStr, str);
		strcat(newStr, string.c_str());

		String s(newStr);
		delete [] newStr;
		return s;
	}

	String operator+(const char* string)
	{
		char* newStr = new char[length() + strlen(string) + 1];
		strcpy(newStr, str);
		strcat(newStr, string);

		String s(newStr);
		delete [] newStr;
		return s;
	}

	String& operator += (const String& string)
	{
		*this = *this + string;
		return *this;
	}

	String& operator += (const char* str)
	{
		*this = *this + str;
		return *this;
	}

	char operator[](int index)
	{
		if (index >=0 && index < length())
		{
			return str[index];
		}

		exit(1);
	}

	bool operator == (const String& string)
	{
		return !strcmp(this->str, string.c_str());
	}

	bool operator == (const char* str)
	{
		return !strcmp(this->str, str);
	}

	bool operator != (const String& string)
	{
		return !(*this == string);
	}

	bool operator != (const char* str)
	{
		return !(*this == str);
	}

	bool operator < (const String& string)
	{
		return ( strcmp(str, string.c_str()) < 0 ) ? true : false;
	}

	bool operator < (const char* str)
	{
		return ( strcmp(this->str, str) < 0 ) ? true : false;
	}

	bool operator > (const String& string)
	{
		return ( strcmp(str, string.c_str() ) > 0 ) ? true : false;
	}

	bool operator > (const char* str)
	{
		return ( strcmp(this->str, str) > 0 ) ? true : false;
	}

	friend String operator+(const char* left, const String& right);
	friend bool operator == (const char* left, const String& right);
	friend bool operator != (const char* left, const String& right);
	friend bool operator < (const char* left, const String& right);
	friend bool operator > (const char* left, const String& right);
};

String operator+(const char* left, const String& right)
{
	String s(left);

	s = s + right;

	return s;
}

bool operator == (const char* left, const String& right)
{
	return !strcmp(left, right.c_str());
}

bool operator != (const char* left, const String& right)
{
	return !(left == right);
}

bool operator < (const char* left, const String& right)
{
	return ( strcmp(left, right.c_str()) < 0 ) ? true : false;
}

bool operator > (const char* left, const String& right)
{
	return ( strcmp(left, right.c_str()) > 0 ) ? true : false;
}

int main()
{
	String s;

	s += "Hello";

	cout << s.c_str() << endl;

	String s2(", World!");

	s += s2;

	cout << s.c_str() << endl;

	cout << s.length() << endl;

	cout << s[4] << endl;

	cout << (s != s2) << endl;

	String car1("Car");
	String car2("Car");

	cout << (car1 == car2) << endl;

	String a("abc");
	String b("ccc");

	if ( a < b )
	{
		cout << a.c_str();
	}
	else
	{
		cout << b.c_str();
	}
	cout << endl;

	b = "This is a new string.";
	cout << b.c_str() << endl;

	String c;
	c = s + " " + b;

	cout << c.c_str() << endl;

	return 0;
}
