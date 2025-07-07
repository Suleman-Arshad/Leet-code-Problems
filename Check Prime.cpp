#include <iostream>
using namespace std;
int countPrimes(int n)
{
    int count = 0;
    if (n <= 1)
    {
        count = 0;
        /* code */
    }
    else
    {
        for (int i = 2; i < n; i++)
        {
            bool isprime = true;
            for (int j = 2; j * j <= i; j++)
            {
                if (i % j == 0)
                {
                    isprime = false;
                    break;
                }
            }
            /* code */
            if (isprime)
            {
                count++;
            }
        }
    }
    return count;
}
int main()
{
    int n;
    cout<<"Enter range : ";
    cin>>n;
    cout << countPrimes(n) << endl;

    system("pause");
    return 0;
}
