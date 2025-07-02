#include <iostream>
#include <stack>
using namespace std;
int main()
{
    string s = "Suleman";
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];
        st.push(c);
    }
    string ans = "";
    while (!st.empty())
    {
        char c = st.top();
        ans.push_back(c);
        /* code */
        st.pop();
    }
    cout << ans << endl;
    system("pause");
    return 0;
}