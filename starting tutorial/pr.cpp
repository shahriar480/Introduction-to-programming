#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
 int arr[10]={12,32,43,54,53,15,64,3,13};
 std::cout << "Normal order: ";
 for (int i=0; i<10; ++i){
    std::cout << arr[i] << " ";
 }
 std :: cout << : "\nReverse order: ";
 for (int i=9; i>=0; --i){
    std::cout << arr[i] << " ";
 }

getch();
}
