#pragma once
class MyStr
{
	char* str;
	int len;
public:
	MyStr();
	MyStr(int l);
	MyStr(char* str);
	~MyStr();
	void Input();
	void Output();
	void MyStrcpy(MyStr& obj);
	bool MyStrStr(const char* str);
	int  MyChr(char c);
	int  MyStrLen();
	void MyStrCat(MyStr& b);
	void MyDelChr(char c);
	int  MyStrCmp(MyStr& b);

	char& operator[](const int index);
	void operator() (const char* enter);
};

