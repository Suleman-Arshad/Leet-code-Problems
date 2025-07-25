#include <iostream>
#include <vector>
using namespace std;
void rotate(vector<int> &nums, int k)
{
    int n = nums.size();
    k %= n; // Handle k > n

    vector<int> temp(n); // Extra array

    for (int i = 0; i < n; i++)
    {
        temp[(i + k) % n] = nums[i];
    }

    // Copy back to nums
    for (int i = 0; i < n; i++)
    {
        nums[i] = temp[i];
    }
}
int main()
{
    vector<int> nums;
    int k;
    cout << "Enter value of K : ";
    cin >> k;
    cin.clear();
    cin.ignore();
    int n;
    cout << "Enter Elements in an array : ";
    while (cin >> n)
    {
        /* code */
        nums.push_back(n);
    }
    rotate(nums, k);
    cout<<"Rotated Array \n";
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << endl; /* code */
    }

    return 0;
}