#include <iostream>
#include <conio.h>
using namespace std;
bool isPrime(int n)
{
    if (n <= 1)
    {
        return false;
    }
    if (n <= 3)
    {
        return true;
    }
    if (n % 2 == 0 || n % 3 == 0)
    {
        return false;
    }
    for (int i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
        {
            return false;
        }
    }
    return true;
}

int factorial(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    return n * factorial(n - 1);
}

int main()
{
    int num;
    std::cout << "Enter an integer: ";
    std::cin >> num;

    if (isPrime(num))
    {
        int fact = factorial(num);
        std::cout << "Factorial of " << num << " is: " << fact << std::endl;
    }
    else
    {
        std::cout << "Error! Not a prime number." << std::endl;
    }

    getch();
}
