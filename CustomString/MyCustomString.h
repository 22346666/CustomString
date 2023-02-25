#pragma once
#include <iostream>
using namespace std;
class MyCustomString
{
	friend ostream& operator<<(ostream& stream, MyCustomString& refstr);
	friend istream& operator>>(istream& stream, MyCustomString& refstr);
private:
	char* str;
public:
	MyCustomString();
	MyCustomString(const char* s);
	MyCustomString(const MyCustomString& source);
	MyCustomString(MyCustomString&& source); //Move Constructor
	~MyCustomString();


	void display() const;
	int get_length() const;
	const char* get_string() const;


	//operators


	MyCustomString& operator=(const MyCustomString& refstr);
	MyCustomString& operator=(MyCustomString&& refstr); //Move assignment
	bool operator==(MyCustomString& refstr) const;
	bool operator!=(MyCustomString& refstr) const;
	MyCustomString operator-() const;
	MyCustomString operator+() const;
	MyCustomString operator+(const MyCustomString& refstr);
	MyCustomString operator*(const int n);
	MyCustomString& operator*=(const int n);
};

