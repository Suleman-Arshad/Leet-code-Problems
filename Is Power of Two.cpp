#include <iostream>
#include <cmath>
using namespace std;
bool isPowerOfTwo(int n)
{
    if (n == 0)
    {
        return false;
    }
    while (n % 2 == 0)
    {
        n /= 2;
    }
    return n == 1;
}
int main()
{
    int n;
    cout << "Enter Number : ";
    cin >> n;
    if (isPowerOfTwo(n))
    {
        cout << "Yes, the number " << n << " is a Power of Two.\n";
    }
    else
    {
        cout << "NO, the number " << n << " is not a Power of Two.\n";
    }
    return 0;
}