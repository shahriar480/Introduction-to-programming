#include<iostream>
#include<conio.h>
#include<iomanip>
using namespace std;
int main()
{
    int num1,num2;
    cout << "Enter 2 numbers";
    cin >>num1 >> num2;
    cout<<showpoint;
    cout<<fixed;
    cout<<setprecision(2);

    int sum = num1 + num2;
    cout <<setw(15) << " The Sum is :" << sum;
    cout <<endl;

    int sub = num1 - num2;
    cout <<setw(15) <<"Subtraction is :" << sub;
    cout << endl;

    int mul = num1 * num2;
    cout <<setw(15) << "Multiplication is :" << mul;
    cout << endl;

    double div = (float) num1 / num2;
    cout <<setw(15) << "Division is :" << div;
    cout << endl;

    int rem = num1 % num2 ;
    cout << "Remainder is :" << rem;
    cout <<endl;

    getch();
}
