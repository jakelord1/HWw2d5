#pragma once
class MyStr
{
	char* str;
	int len;
public:
	MyStr();
	MyStr(int l);
	MyStr(const char* str);
	MyStr(MyStr& obj);
	MyStr(MyStr&& obj);
	~MyStr();
	char* GetStr() const;
	void SetStr(const char* e);
	void SetL(int l);
	int GetL() const;
	void Input();
	void Output() const;
	void MyStrcpy(MyStr& obj);
	//bool MyStrStr(const char* str);
	int  MyChr(char c);
	int  MyStrLen() const;
	void MyStrCat(MyStr& b);
	void MyDelChr(char c);
	int  MyStrCmp(MyStr& b) const;

	char& operator[](const int index);
	void operator() (const char* enter);
	MyStr& operator=(const MyStr& ob);
	MyStr& operator=(MyStr&& obj);
	
	char* operator*(int am) const;
	char* operator/(int am) const;
	bool operator==(MyStr ob) const;
	bool operator!=(MyStr ob) const;
	bool operator>=(MyStr ob) const;
	bool operator<=(MyStr ob) const;
};

