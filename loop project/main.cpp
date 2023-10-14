#include <iostream>

using namespace std;

int main()
{
    int n, triNUm;
    triNUm = 0;
    for ( n = 1 ; n <= 2000 ; n = n + 1)
        triNUm = triNUm + n;
          //cout<<n<<endl ;

    cout<<"The 2000th triangular number = " << triNUm ;

    return 0;
}
