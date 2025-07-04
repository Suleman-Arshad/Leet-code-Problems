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

vector<int> searchRange(vector<int> &nums, int target)
{
    vector<int> newarr;

    // Find first and last index of target
    int start = -1, end = -1;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == target)
        {
            if (start == -1)
                start = i;
            end = i;
        }
    }

    // Push result to newarr
    newarr.push_back(start);
    newarr.push_back(end);

    return newarr;
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
    cout << "Enter numbers followed by EOF (Ctrl+Z on Windows / Ctrl+D on Unix):" << endl;
    push(arr);

    vector<int> result = searchRange(arr, 8);
    display(result);

    return 0;
}
