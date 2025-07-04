#include <iostream>
#include <vector>
using namespace std;
void push(vector<int> &arr)
{
    int n;
    while (cin >> n)
    {
        arr.push_back(n);
    }
}
int removeElement(vector<int> &nums, int target)
{
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        if (nums[i] == target)
        {
            nums.erase(nums.begin() + i);
        }
    }
    int size;
    size = nums.size();
    return size;
}
void display(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << endl;
    }
}
int main()
{
    vector<int> arr;
    int val;
    cout << "Enter value to remove in an array : ";
    cin >> val;
    cout << "Enter element of an array" << endl;
    push(arr);
    cout << "Size of Modified array : "<<removeElement(arr, val)<<endl;
    cout << "Modified array\n";
    display(arr);
    return 0;
}
