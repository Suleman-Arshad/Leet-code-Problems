#include <iostream>
#include <vector>
using namespace std;
int countStudents(vector<int> &students, vector<int> &sandwiches)
{
    int count = 0;
    while (!students.empty())
    {
        if (students[0] == sandwiches[0])
        {
            students.erase(students.begin());
            sandwiches.erase(sandwiches.begin());
            count = 0;
        }
        else
        {
            int b = students[0];
            students.push_back(b);
            students.erase(students.begin());
            count++;
            if (count == students.size())
            {
                break;
            }
        }
    }
    return students.size();
}
int main()
{
    vector<int> students;
    vector<int> sandwiches;
    int s;
    int sa;
    cout << "Enter Students Prefrence \n";
    while (cin >> s)
    {
        students.push_back(s);
        /* code */
    }
    cin.clear();
    cin.ignore();
    cout << "Enter Sandwiches \n";
    while (cin >> sa)
    {
        sandwiches.push_back(s);
        /* code */
    }
    cout << "Number of Students not able to eat : " << countStudents(students, sandwiches) << endl;

    system("pause");
    return 0;
}