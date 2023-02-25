#include "MyCustomString.h"
#include <cstring>
#include <iostream>
#define _SRT_SECURE_NO_WARNINGS
using namespace std;

MyCustomString::MyCustomString() : str(nullptr)
{
	str = new char[1];
	*str = '\0';
}

MyCustomString::MyCustomString(const char* s) : str(nullptr)
{
	if (s == nullptr) {
		str = new char[1];
		*str = '\0';
	}
	else {
		str = new char[strlen(s) + 1];
		strcpy(str, s);
	}
}

MyCustomString::MyCustomString(const MyCustomString& source) : str(nullptr)
{
	str = new char[strlen(source.str) + 1];
	strcpy(str, source.str);
}

MyCustomString::MyCustomString(MyCustomString&& source) : str(source.str) 
{
	source.str = nullptr;
}

MyCustomString::~MyCustomString()
{
	delete[] str;
}

void MyCustomString::display() const
{
	cout << str << ':' << strlen(str) << endl;
}

int MyCustomString::get_length() const
{
	return strlen(str);
}

const char* MyCustomString::get_string() const
{
	return str;
}

MyCustomString& MyCustomString::operator=(const MyCustomString& refstr)
{
	if (this == &refstr) {
		//cout << "Copy assignmemt";
		return *this;
	}
	delete[] this->str;
	str = new char[strlen(refstr.str) + 1];
	int i = 0;
	strcpy(str, refstr.str);
	return *this;
}

MyCustomString& MyCustomString::operator=(MyCustomString&& refstr)
{
	if (this == &refstr) {
		return *this;
	}
	delete[] str;
	this->str = refstr.str;
	refstr.str = nullptr;
	return *this;
}

bool MyCustomString::operator==(MyCustomString& refstr) const
{
	return (strcmp(str, refstr.str) == 0) ? true : false;
}

bool MyCustomString::operator!=(MyCustomString& refstr) const
{
	return (strcmp(str, refstr.str) != 0) ? true : false;
}

MyCustomString MyCustomString::operator-() const
{
	char* buffer = new char[strlen(this->str)+1];
	strcpy(buffer, str);
	for (int i{}; i < strlen(str); i++) {
		buffer[i] = tolower(buffer[i]);
	}
	MyCustomString temp(buffer);
	delete[] buffer;
	return temp;
}

MyCustomString MyCustomString::operator+() const
{
	char* buffer = new char[strlen(this->str) + 1];
	strcpy(buffer, str);
	for (int i{}; i < strlen(str); i++) {
		buffer[i] = toupper(buffer[i]);
	}
	MyCustomString temp(buffer);
	delete[] buffer;
	return temp;
}

MyCustomString MyCustomString::operator+(const MyCustomString& refstr)
{
	int buff_size = strlen(str) + strlen(refstr.str) + 1;
	char* buff = new char[buff_size];
	strcpy(buff, str);
	strcat(buff, refstr.str);
	MyCustomString temp{ buff };
	delete[] buff;
	return temp;
}

MyCustomString MyCustomString::operator*(const int n)
{
	if (n == 0) {
		return MyCustomString();
	}
	MyCustomString buffer = str;
	for (int i = 0; i < n-1; i++) {
		buffer = buffer+*this;
	}
	return buffer;
}

MyCustomString& MyCustomString::operator*=(const int n)
{
	if (n == 0) {
		strcpy(str, "\0");
		return *this;
	}
	MyCustomString copy(*this);
	for (int i = 0; i < n - 1; i++) {
		*this=*this+ copy;
	}
	return *this;
}

ostream& operator<<(ostream& stream, MyCustomString& refstr)
{
	stream << refstr.str;
	return stream;
}

istream& operator>>(istream& stream, MyCustomString& refstr)
{
	char* buffer = new char[1000];
	stream >> buffer;
	refstr = MyCustomString(buffer);
	delete[] buffer;
	return stream;
}
