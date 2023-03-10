// By - Kaustav Purkayastha ( Gurucharan University, Silchar - @ Department of Computer Science )

/* 2. Create matrix class using templates. Write a C++ program to perform the
	following matrix operations (2D array implementation):
	(i) Sum, (ii) Difference, (iii) Product, (iv) Transpose		*/


#include<iostream>
#include<process.h>
using namespace std;

template<class T>
class matrix
{
    T A[10][10], B[10][10], C[10][10], P[10][10], T1[10][10], T2[10][10];
    int r1, c1, r2, c2, i, j, k;
public:
    void getdata();
    void display();
    void sum();
    void difference();
    void product();
    void transpose();
};

template<class T>void matrix<T>::getdata()
{
    cout<<"Enter the no. of rows and columns of the first matrix: ";
    cin>>r1>>c1;
    cout<<"Enter the values of first matrix: ";
    for(i=0; i<r1; i++)
    {
        for(j=0; j<c1; j++)
            cin>>A[i][j];
    }
    cout<<"Enter the no. of rows and columns of the second matrix: ";
    cin>>r2>>c2;
    cout<<"Enter the values of second matrix: ";
    for(i=0; i<r2; i++)
    {
        for(j=0; j<c2; j++)
            cin>>B[i][j];
    }
}

template<class T>void matrix<T>::display()
{
    cout<<"\nThe Entered First Matrix is: \n";
    for(i=0; i<r1; i++)
    {
        for(j=0; j<c1; j++)
            {
                cout<<"\t"<<A[i][j];
            }
        cout<<"\n";
    }

    cout<<"\nThe Entered Second Matrix is:\n";
    for(i=0; i<r2; i++)
    {
        for(j=0; j<c2; j++)
            {
                cout<<"\t"<<B[i][j];
            }
        cout<<"\n";
    }
}

template<class T>void matrix<T>::sum()
{
if(r1==r2 && c1==c2)
    {
        for(i=0; i<r1; i++)
        {
            for(j=0; j<c2; j++)
            C[i][j] = A[i][j]+B[i][j];
        }
        cout<<"\nThe sum of the given two matrices is: \n";
        {
            for(i=0; i<r1; i++)
            {
            for(j=0; j<c2; j++)
                {
                    cout<<"\t"<<C[i][j];
                }
            cout<<"\n";
            }
        }
    }
     else
        cout<<"\nThe addition is not possible.\n";
}

template<class T>void matrix<T>::difference()
{
    if(r1==r2 && c1==c2)
    {
        for(i=0; i<r1; i++)
        {
            for(j=0; j<c2; j++)
            C[i][j] = A[i][j]-B[i][j];
        }
        cout<<"\nThe difference of the given two matrices is: \n";
        {
            for(i=0; i<r1; i++)
            {
            for(j=0; j<c2; j++)
                {
                    cout<<"\t"<<C[i][j];
                }
            cout<<"\n";
            }
        }
    }
     else
        cout<<"\nThe substraction is not possible.\n";
}

template<class T>void matrix<T>::product()
{
    if(c1==r2)
    {
        for(i=0; i<r1; i++)
        {
            for(j=0; j<c2; j++)
            {
            	P[i][j] = 0;
                for(k=0; k<c1; k++)
                {
                	P[i][j] += A[i][k]*B[k][j];
                }
            }
        }
        cout<<"\nThe product of the given two matrices is: \n";
        {
            for(i=0; i<r1; i++)
            {
            	for(j=0; j<c2; j++)
                {
                    cout<<"\t"<<P[i][j];
                }
            cout<<"\n";
            }
        }
    }
     else
        cout<<"\nThe multiplication is not possible.\n";
}

template<class T>void matrix<T>::transpose()
{
  {
    for(i=0; i<r1; i++)
    {
        for(j=0; j<c1; j++)
            {
                T1[j][i] = A[i][j];
            }
    }
  }
  {
    for(i=0; i<r2; i++)
    {
        for(j=0; j<c2; j++)
            {
                T2[j][i] = B[i][j];
            }
    }
  }
    cout<<"\nThe Transpose of the first matrix is: \n";
    {
    for(i=0; i<c1; i++)
    {
        for(j=0; j<r1; j++)
            {
                cout<<"\t"<<T1[i][j];
            }
          cout<<"\n";
    }
}
    cout<<"\nThe Transpose of the second matrix is: \n";
    {
    for(i=0; i<c2; i++)
    {
        for(j=0; j<r2; j++)
            {
                cout<<"\t"<<T2[i][j];
            }
        cout<<"\n";
    }
    }
}

int main()
{
    int n;
    matrix<int> M;
    M.getdata();
    M.display();

    choice:
        cout<<"\nOperations: \n";
        cout<<"1) Enter 1 to perform addition.\n";
        cout<<"2) Enter 2 to perform substraction.\n";
        cout<<"3) Enter 3 to perform multiplication.\n";
        cout<<"4) Enter 4 to display transpose.\n";
        cout<<"5) Enter 0 to exit the program.\n";
        cout<<"\nEnter your choice: ";
        cin>>n;

        switch(n)
        {
        case 1: M.sum();
                break;

        case 2: M.difference();
                break;

        case 3: M.product();
                break;

        case 4: M.transpose();
                break;

        case 0: cout<<"\nExiting the program.....\n";
                exit(0);

        default: cout<<"\nInvalid Choice!!!\n";
        }
    goto choice;
    
    return 0;
}
