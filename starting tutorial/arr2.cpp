#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int arr[10] = {12, 32, 43, 1,54,53,15,64,3,13};
    int evenCount = 0;
    int oddCount = 0;

    for (int i= 0; i<10; ++i)
    {
        if(arr[i] % 2==0)
        {
            evenCount++;
        }
        else
        {
            oddCount++;
        }

    }
    std::cout << evenCount << "even numbers" << std::endl;
    std::cout << oddCount << "odd numbers" << std::endl;

    getch();

}
