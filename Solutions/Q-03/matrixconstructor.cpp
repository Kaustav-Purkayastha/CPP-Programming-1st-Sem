// By - Kaustav Purkayastha ( Gurucharan University, Silchar - @ Department of Computer Science )

/* 3. Create matrix class using templates. Write a C++ program that reads two Matrix(2D array)
	  using constructor and perform multiplication operation.		*/


#include<iostream>
using namespace std;

template<class T>
class matrix
{
    T **P1, **P2, **P3;
    int i, j, k, r1, c1, r2, c2;
    int add;
public:
    matrix()
    {
        cout<<"Enter the rows and columns of first matrix: ";
        cin>>r1>>c1;
        cout<<"Enter the rows and columns of second matrix: ";
        cin>>r2>>c2;

        P1 = new int *[r1];
        for(i=0; i<r1; i++)
        {
            P1[i] = new int [c1];
        }
        P2 = new int *[r2];
        for(i=0; i<r2; i++)
        {
            P2[i] = new int [c2];
        }
        P3 = new int *[r1];
        for(i=0; i<r1; i++)
        {
            P3[i] = new int [c2];
        }
    }
    void getdata();
    void display();
    void product();
};

template<class T>void matrix<T>::getdata()
{
    cout<<"\nEnter the elements of the first matrix: ";
    for(i=0; i<r1; i++)
    {
        for(j=0; j<c1; j++)
        cin>>P1[i][j];
    }
    cout<<"\nEnter the elements of the second matrix: ";
    for(i=0; i<r2; i++)
    {
        for(j=0; j<c2; j++)
        cin>>P2[i][j];
    }
}

template<class T>void matrix<T>::display()
{
    cout<<"\nThe Entered First Matrix is: \n";
    for(i=0; i<r1; i++)
    {
        for(j=0; j<c1; j++)
        {
            cout<<"\t"<<P1[i][j];
        }
        cout<<"\n";
    }
    cout<<"\nThe Entered Second Matrix is: \n";
    for(i=0; i<r2; i++)
    {
        for(j=0; j<c2; j++)
        {
            cout<<"\t"<<P2[i][j];
        }
        cout<<"\n";
    }
}

template<class T>void matrix<T>::product()
{
    if(c1==r2)
    {
        for(i=0; i<r1; i++)
        {
            for(j=0; j<c2; j++)
            {
              for(k=0; k<c1; k++)
              {
                  add += P1[i][k]*P2[k][j];
              }
             P3[i][j] = add;
             add = 0;
            }
        }
        cout<<"\nThe product of the given matrices is: \n";
        for(i=0; i<r1; i++)
        {
            for(j=0; j<c2; j++)
            {
                cout<<"\t"<<P3[i][j];
            }
            cout<<"\n";
        }
    }
    else
        cout<<"\nThe multiplication is not possible!!!\n";
}

int main()
{
    matrix<int>M;
    M.getdata();
    M.display();
    M.product();
    return 0;
}
