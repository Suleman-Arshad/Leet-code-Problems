#include <iostream>
#include <vector>
using namespace std;
void binarysearch(vector<int> &arr)
{
    int element;
    bool check = false;
    cout << "Enter Element to Search in an array : ";
    cin >> element;
    int low, mid, high;
    low = 0;
    high = arr.size() - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == element)
        {
            cout << "Element " << element << " found at " << mid << " index\n";
            check = true;
            break;
            /* code */
        }
        else if (arr[mid] < element)
        {
            low = mid + 1;
            /* code */
        }
        else
        {
            /* code */
            low = mid - 1;
        }
        /* code */
    }
    if (!check)
    {
        cout << "No such Element fouund in an array\n";
        /* code */
    }
}
void LinearSearch(vector<int> &arr)
{
    int element;
    bool check = false;
    cout << "Enter Element to found : ";
    cin >> element;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == element)
        {
            cout << "Element " << element << " found at " << i << " index\n";
            check = true;
            break;
            /* code */
        }
        /* code */
    }
    if (!check)
    {
        cout << "No Such element Found\n";
        /* code */
    }
}
void Sorting(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr.size(); j++)
        {
            if (arr[i] <= arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                /* code */
            }

            /* code */
        }

        /* code */
    }
}
void display(vector<int> &arr)
{
    cout << "Elements of an array\n";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << endl;
        /* code */
    }
}
void input(vector<int> &arr)
{
    cout << "First enter elements in an array then perform operations on it \n";
    int n;
    while (cin >> n)
    {
        arr.push_back(n);
        /* code */
    }
}
int main()
{
    vector<int> arr;
    int choice;
    cout << "========== Binary Search , Sorting and Linear Search Combo ==========\n";
    input(arr);
    cin.clear();
    cin.ignore();
start:
    cout << "\n\n\n\nPress 1 for display elements of an array\nPress 2 for Sorting\nPress 3 for Linear Search\nPress 4 for Binary Search\nPress 5 for Exit\n";
    cout << "Press : ";
    cin >> choice;
    while (choice < 1 || choice > 5)
    {
        cout << "Press a valid number between (1 to 5) : ";
        cin >> choice;
        /* code */
    }
    switch (choice)
    {
    case 1:
        display(arr);
        goto start;
        break;
    case 2:
        Sorting(arr);
        goto start;
        break;
    case 3:
        LinearSearch(arr);
        goto start;
        break;
    case 4:
        Sorting(arr);
        binarysearch(arr);
        goto start;
        break;
    case 5:
        cout << "Exiting.......\n";
        break;
    default:
        cout << "Invalid\n";
        break;
    }
    system("pause");
    return 0;
}