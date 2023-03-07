// By - Kaustav Purkayastha ( Gurucharan University, Silchar - @ Department of Computer Science )

/* 5. Create a class triangle. Include overloaded functions for calculating area.
	  Overload assignment operator and equality operator.		*/


#include<iostream>
#include<process.h>
#include<math.h>
using namespace std;

class triangle
{
    float e1, e2, b, h;
    double area;
public:
    triangle()
    {
        e1=e2=b=h=0;
        area=0;
    }
    
    triangle(float E1, float E2, float B)
    {
        e1=E1;
        e2=E2;
        b=B;
        h=0;
        area=AREA(e1,e2,b);
    }
    
    triangle(float B, float H)
    {
        b=B;
        h=H;
        e1=e2=0;
        area=AREA(b,h);
    }
    
    triangle(float K)
    {
        e1=e2=b=K;
        h=0;
        area=AREA(b);
    }
    
    double AREA(float s1, float s2, float s3)
    {
        double X;
        float p, s;
        p = s1+s2+s3;
        s = p/2;
        X = sqrt((s)*(s-s1)*(s-s2)*(s-s3));
        return X;
    }
    
    double AREA(float b1, float h1)
    {
        double X;
        X = (b1*h1)/2;
        return X;
    }
    
    double AREA(float s)
    {
        cout<<"\nEquilateral Triangle: \n";
        return (AREA(s,s,s));
    }
    
    int operator== (triangle X)
    {
        cout<<"\nComparing the areas: \n";
        int a=0;
        if(area==X.area)
            a=1;
        return a;
    }
    
    void operator= (triangle X)
    {
        cout<<"\nAssigning values: \n";
        e1=X.e1;
        e2=X.e2;
        h=X.h;
        b=X.b;
        area=X.area;
    }
    
    void display();
};

void triangle::display()
{
    if(e1)
    {
        cout<<"\nEdge 1 = "<<e1;
        cout<<"\nEdge 2 = "<<e2;
        cout<<"\nEdge 3 = "<<b;
    }
    if(h)
    {
        cout<<"\nBase = "<<b;
        cout<<"\nHeight = "<<h;
    }
    cout<<"\n\nArea of the triangle = "<<area;
}

void menu(triangle &x)
{
    int n;

    menu:
    cout<<"\n\nHow do you want to find the area of the triangle???\n\n";
    cout<<"1) Press 1 to use the dimensions of the three sides.\n";
    cout<<"2) Press 2 to use the base and height.\n";
    cout<<"3) Press 3 to calculate the area of an equilateral triangle.\n";
    cout<<"4) Press 4 to use assignment operator(=).\n";
    cout<<"5) Press 5 to use equality operator(==).\n";
    cout<<"6) Press 0 to exit the program.\n";

    cout<<"\nEnter your choice: ";
    cin>>n;

    switch(n)
    {
    case 1:
        {
            float a, b, c;
            cout<<"\nEnter the three sides of the triangle: ";
            cin>>a>>b>>c;
            triangle t(a,b,c);
            t.display();
            break;
        }
    case 2:
        {
            float b, h;
            cout<<"\nEnter the base and height of the triangle: ";
            cin>>b>>h;
            triangle t(b,h);
            t.display();
            break;
        }
    case 3:
        {
            float s;
            cout<<"\nEnter one side of the equilateral triangle: ";
            cin>>s;
            triangle t(s);
            t.display();
            break;
        }
    case 4:
        {
            float a, b, c;
            cout<<"\nEnter three sides: ";
            cin>>a>>b>>c;
            triangle t(a,b,c);
            x=t;
            x.display();
            break;
        }
    case 5:
        {
            float a, b, c;
            cout<<"\nEnter the three sides of the first triangle: ";
            cin>>a>>b>>c;
            triangle t1(a,b,c);
            cout<<"Enter the three sides of the second triangle: ";
            cin>>a>>b>>c;
            triangle t2(a,b,c);
            if(t1==t2)
                {
                    cout<<"\nThe area of the two triangles are equal\n";
                }
            else
                {
                    cout<<"\nThe area of the two triangles are not equal\n";
                }
            break;
        }
    case 0:
        {
            cout<<"\nExiting the program.....\n";
            exit(0);
        }
    default:
        cout<<"\nInvalid Choice!!!\n";
    }
    goto menu;
}

int main()
{
    triangle x;
    menu(x);
    return 0;
}
