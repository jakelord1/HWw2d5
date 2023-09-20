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

MyStr::MyStr(const char* sr)
{
	str = new char[strlen(sr) + 1];
	strcpy_s(str, strlen(sr) + 1, sr);
	str[strlen(sr)] = '\0';
	len = strlen(str) + 1;
}

MyStr::MyStr(MyStr& obj)
{
	obj.str = new char[strlen(str) + 1];
	strcpy_s(obj.str, strlen(str) + 1, str);
	obj.len = len;
}

MyStr::MyStr(MyStr&& obj)
{
	len = obj.len;
	obj.len = 0;
	str = obj.str;
	obj.str = nullptr;
}

MyStr::~MyStr()
{
	str = nullptr;
	delete[] str;
}

char* MyStr::GetStr() const
{
	return str;
}

void MyStr::SetStr(const char* e)
{
	if (str != nullptr) {
		delete[] str;
	}
	str = new char[strlen(e) + 1];
	strcpy_s(str, strlen(e) + 1, e);
	len = strlen(e);
}

void MyStr::SetL(int l)
{
	len = l;
}

int MyStr::GetL() const
{
	return len;
}

void MyStr::Input()
{
	char ent[80];
	std::cin >> ent;
	str = new char[strlen(ent) + 1];
	strcpy_s(str, strlen(ent) + 1, ent);
	len = strlen(str) + 1;
}

void MyStr::Output() const
{
	std::cout << str << std::endl;
}

void MyStr::MyStrcpy(MyStr& obj)
{
	obj.str = new char[strlen(str) + 1];
	strcpy_s(obj.str, strlen(str) + 1, str);
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

int MyStr::MyStrLen() const
{
	return len;
}

void MyStr::MyStrCat(MyStr& b)
{
	char* buff = new char[strlen(str) + 1];
	strcpy_s(buff, strlen(str) + 1, str);
	str = new char[strlen(buff) + strlen(b.str) + 1];
	for (size_t i = 0; i < strlen(buff); i++)
	{
		str[i] = buff[i];
	}
	for (size_t i = strlen(buff); i < strlen(str); i++)
	{
		str[i] = b.str[i - strlen(buff)];
	}
	delete[] buff;
}

void MyStr::MyDelChr(char c)
{
	char* buff = new char[strlen(str)+1];
}

int MyStr::MyStrCmp(MyStr& b) const
{
	if (str == b.str)
		return 0;
	else if (str > b.str)
		return 1;
	else
		return -1;
	
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

MyStr& MyStr::operator=(const MyStr& ob)
{
	if (this != &ob) {
		delete[] str;
		len = ob.GetL();
		str = new char[ob.GetL()+1];
		strcpy_s(str, ob.GetL() + 1, ob.GetStr());
	}
	return *this;
}

MyStr& MyStr::operator=(MyStr&& obj)
{
	this->str = obj.str;
	obj.str = nullptr;
	len = obj.len;
	obj.len = 0;
	return *this;
}

char* MyStr::operator*(int am) const
{
	char* ret = new char[am+1];
	strcpy_s(ret, am, str);
	ret[am] = '\0';
	return ret;
}

char* MyStr::operator/(int am) const
{	
	if (am >= 0) {
		char* ret = new char[am + 1]; int k = 0;
		for (size_t i = strlen(str); i > strlen(str) - am; i--)
		{
			ret[k] = str[i];
			k++;
		}
		ret[am] = '\0';
		return ret;
	}
	else {
		char* ret = new char[100];
		for (size_t i = 0; i < 99; i++)
		{
			ret[i] = '0';
		}
		ret[99] = '\0';
		return ret;
	}
}

bool MyStr::operator==(MyStr ob) const
{
	if (str == ob.str) 
		return true;
	else
		return false;
}
bool MyStr::operator!=(MyStr ob) const
{
	if (str != ob.str)
		return true;
	else
		return false;
}

bool MyStr::operator>=(MyStr ob) const
{
	if (str <= ob.str)
		return true;
	else
		return false;
}

bool MyStr::operator<=(MyStr ob) const
{
		if (str <= ob.str)
			return true;
		else
			return false;
}
