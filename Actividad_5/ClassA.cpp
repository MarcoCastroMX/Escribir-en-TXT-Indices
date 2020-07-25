#include "ClassA.h"

ClassA::ClassA()
{

}

ClassA::ClassA(int A, int B, int C, int D)
{
    this->A=A;
    this->B=B;
    this->C=C;
    this->D=D;
}

int ClassA::getA()
{
    return A;
}

int ClassA::getB()
{
    return B;
}

int ClassA::getC()
{
    return C;
}

int ClassA::getD()
{
    return D;
}

string ClassA::ToString()
{
    stringstream ss;
    ss<<A<<"-"<<B<<"-"<<C<<"-"<<D<<endl;
    string s="";
    s=ss.str();
    return s;
}
