#include <iostream>
#include "MyStr.h"
using namespace std;

ostream& operator<<(ostream& os, MyStr obj) {
    obj.Output();
    return os;
}
istream& operator>>(istream& is, MyStr obj) {
    char ent[80];
    cin >> ent;
    obj.SetStr(ent);
    return is;
}
MyStr operator+(const MyStr& obj1, const char a) {
    MyStr rez;
    rez.SetL(obj1.GetL() + 1);
    const char* origStr = obj1.GetStr();
    char* newStr = new char[rez.GetL() + 1];
    strcpy_s(newStr, rez.GetL() + 1, origStr);
    for (int i = obj1.GetL(); i < rez.GetL(); i++) {
        newStr[i] = a;
    }
    newStr[rez.GetL()] = '\0';
    rez.SetStr(newStr);
    delete[] newStr;
    return rez;
}
MyStr operator+(const char a, const MyStr& obj1) {
    MyStr rez;
    rez.SetL(obj1.GetL() + 1);
    const char* origStr = obj1.GetStr();
    char* newStr = new char[rez.GetL() + 1];
    strcpy_s(newStr, rez.GetL() + 1, origStr);
    for (int i = obj1.GetL(); i < rez.GetL(); i++) {
        newStr[i] = a;
    }
    newStr[rez.GetL()] = '\0';
    rez.SetStr(newStr);
    delete[] newStr;
    return rez;
}
MyStr operator+(const MyStr& obj1, const int a)
{
    MyStr rez;
    rez.SetL(obj1.GetL() + a);
    const char* origStr = obj1.GetStr();
    char* newStr = new char[rez.GetL() + 1];
    strcpy_s(newStr, rez.GetL() + 1, origStr);
    for (int i = obj1.GetL(); i < rez.GetL(); i++) {
        newStr[i] = '.';
    }
    newStr[rez.GetL()] = '\0';
    rez.SetStr(newStr);
    delete[] newStr;
    return rez;
}
MyStr operator+(const int a, const MyStr& obj1)
{
    MyStr rez;
    rez.SetL(obj1.GetL() + a);
    const char* origStr = obj1.GetStr();
    char* newStr = new char[rez.GetL() + 1];
    strcpy_s(newStr, rez.GetL() + 1, origStr);
    for (int i = obj1.GetL(); i < rez.GetL(); i++) {
        newStr[i] = '.';
    }
    newStr[rez.GetL()] = '\0';
    rez.SetStr(newStr);
    delete[] newStr;
    return rez;
}
MyStr& operator++(MyStr& obj) {
    MyStr buff;
    buff.SetStr(obj.GetStr());
    char* newStr = new char[obj.GetL() + 2];
    strcpy_s(newStr, obj.GetL(), buff.GetStr());
    newStr[obj.GetL()] = '.';
    newStr[obj.GetL()+1] = '\0';
    obj.SetStr(newStr);
    return obj;
}
MyStr operator++(MyStr& obj, int d) {
    MyStr buff;
    buff.SetStr(obj.GetStr());
    buff.SetL(obj.GetL());
    char* newStr = new char[obj.GetL() + 2];
    strcpy_s(newStr, obj.GetL(), buff.GetStr());
    newStr[obj.GetL()] = '.';
    newStr[obj.GetL() + 1] = '\0';
    buff.SetStr(newStr);
    buff.SetL(obj.GetL() + 2);
    return buff;
}
int main()
{
    MyStr o1("Maybe its ok");
    cout << o1 << endl;
    o1.MyDelChr('i');
    cout << o1 << endl;
    int a = o1.MyStrLen();
    cout << a << endl;
    MyStr newS = o1 / 2;
    cout << newS << endl;
}
