#include<iostream>
using namespace std;


/*Write a C++ program that creates a class and to perform swapping
of two numbers without using third variable.*/


class exp1
{
    int a, b;
public:
    void getdata();
    void swap();
    void display();
};
void exp1::getdata()
{
    cout<<"Enter two nos.: ";
    cin>>a>>b;
    cout<<"\nThe values of a and b before swapping are: "<<endl;
    cout<<"a="<<a<<", "<<"b="<<b<<endl;
}
void exp1::swap()
{
    a = a+b;
    b = a-b;
    a = a-b;
}
void exp1::display()
{
    cout<<"\nThe values of a and b after swapping are:"<<endl;
    cout<<"a="<<a<<", "<<"b="<<b;
}
int main()
{
    exp1 x;
    x.getdata();
    x.swap();
    x.display();
    return 0;
}
