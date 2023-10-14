#include <iostream>
#include<conio.h>
using namespace std;
int main ()
{

    int x,y,i;


    cout<< "Starting value: " ;
    cin>>x;

    cout<< "Ending value: " ;
    cin>>y;

    for (i=x; i<=y; i++)
    {


        if(i%2 != 0)
        {

            cout<< i <<endl;
        }

    }

    getch();

}
