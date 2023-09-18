#include "MyStr.h"
#include <iostream>
MyStr::MyStr()
{
	str = new char[80];
	len = 80;
}

MyStr::MyStr(int l)
{
	str = new char[l];
	len = l;
}

MyStr::MyStr(char* sr)
{
	str = new char[strlen(sr) + 1];
	strcpy_s(str, strlen(sr) + 1, sr);
	len = strlen(str) + 1;
}

MyStr::~MyStr()
{
	str = nullptr;
	delete[] str;
}

void MyStr::Input()
{
	char ent[80];
	std::cin >> ent;
	str = new char[strlen(ent) + 1];
	strcpy_s(str, strlen(ent) + 1, ent);
	len = strlen(str) + 1;
}

void MyStr::Output()
{
	std::cout << str << std::endl;
}

void MyStr::MyStrcpy(MyStr& obj)
{
	obj.str = new char[strlen(str) + 1];
	for (size_t i = 0; i < strlen(str)+1; i++)
	{
		obj.str[i] = str[i];
	}
	obj.len = len;
}

int MyStr::MyChr(char c)
{
	for (size_t i = 0; i < len; i++)
	{
		if (str[i] == c) {
			return i;
			continue;
		}
	}
	return -1;
}

int MyStr::MyStrLen()
{
	return len;
}

char& MyStr::operator[](const int index)
{
	if (index >= 0 && index < strlen(str) - 1)
		return str[index];
	else
		return str[0];
}

void MyStr::operator()(const char* enter)
{
	str = new char[strlen(enter) + 1];
	strcpy_s(str, strlen(enter) + 1, enter);
	len = strlen(str) + 1;
}
