#include<iostream>
using namespace std;


/*Create the Person class. Create some objects of this class(by taking the information from the user).
Inherit the class Person to create two classes Teacher and Student. Maintain the respective information in the classes
and create, display and delete objects of these two classes(Use Runtime Polymorphism)*/


class Person
{
public:
    char name[20];
    int age;
    virtual void take()
    {
        cout<<"\nEnter the name of the person: ";
        cin.getline(name, 20);
        cout<<"\nEnter the age of the person: ";
        cin>>age;
    }
    virtual void display()
    {
        cout<<"\nThe name of the person is: "<<name;
        cout<<"\nThe age of the person is: "<<age;
    }
};
class Teacher:public Person
{
    string sub;
    int salary;
public:
    void take()
    {
        cout<<"Enter the name of the teacher: ";
        cin.getline(name, 20);
        cout<<"Enter the subject which the teacher teaches: ";
        getline(cin, sub);
        cout<<"Enter the age of the teacher: ";
        cin>>age;
        cout<<"How much salary the teacher earns: ";
        cin>>salary;
    }
    void display()
    {
        cout<<"\nThe name of the teacher is: "<<name;
        cout<<"\nThe subject which the teacher teaches is: "<<sub;
        cout<<"\nThe age of the teacher is: "<<age;
        cout<<"\nThe salary earned by the teacher is: "<<salary;
    }
};
class Student:public Person
{
    int Class, rollno;
public:
    void take()
    {
        cout<<"\n\nEnter the name of the student: ";
        cin>>name;
        cout<<"Enter the age of the student: ";
        cin>>age;
        cout<<"Enter the class of the student: ";
        cin>>Class;
        cout<<"Enter the roll no. of the student: ";
        cin>>rollno;
    }
    void display()
    {
        cout<<"\nThe name of the student is: "<<name;
        cout<<"\nThe age of the student is: "<<age;
        cout<<"\nThe class of the student is: "<<Class;
        cout<<"\nThe roll no. of the student is: "<<rollno<<endl;
    }
};
int main()
{
    Person *ptr1, *ptr2 = new Person();
    Teacher t;
    Student s;

    ptr1 = &t;
    ptr2 = &s;

    ptr1 -> take();
    ptr1 -> display();

    ptr2 -> take();
    ptr2 -> display();

    return 0;
}
