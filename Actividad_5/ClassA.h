#ifndef CLASSA_H
#define CLASSA_H
#include <iostream>
#include <sstream>

using namespace std;

class ClassA
{
private:
    int A,B,C,D;
public:
    ClassA();
    ClassA(int,int,int,int);
    int getA();
    int getB();
    int getC();
    int getD();
    string ToString();
};

#endif // CLASSA_H
