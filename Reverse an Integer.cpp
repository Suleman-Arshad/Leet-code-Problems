#include <iostream>
#include <climits> // This Library is used to add the Limits Like INT_MAX and MIN
using namespace std;
int reverse(int x)
{
    long long rev = 0;
    while (x != 0)
    {
        long long temp = x % 10;
        rev = (rev * 10) + temp;
        x /= 10;
        /* code */
    }
    if (rev < INT32_MIN || rev > INT32_MAX)
    {
        return 0;
        /* code */
    }
    else
    {
        return static_cast<int>(rev); // At line 21, I type-cast the rev from long long data-type to int
    }
}
int main()
{
    int num;
start:
    cout << "Enter Num to reverse : ";
    cin >> num;
    cout << "Reverse of " << num << " is " << reverse(num) << "." << endl;
    int choice;
    cout << "Press 1 if you want reverse of more num otherwise press 2 to Exit : ";
    cin >> choice;
    while (choice < 1 || choice > 2)
    {
        cout << "Enter Either 1 or 2 : ";
        cin >> choice;
        /* code */
    }
    if (choice == 1)
    {
        goto start;
    }
    else if (choice == 2)
    {
        cout << "Exiting......\n";
    }
    system("pause");
    return 0;
}