#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        string s;
        cin >> s;
        int n = s.length();
        stack<char> st;
        for (int i = 0; i < n; i++) {
            if (!st.empty() && st.top() == s[i]) {
                st.pop();
            } else {
                st.push(s[i]);
            }
        }
        cout << (st.empty() ? "YES" : "NO") << endl;
    }
    return 0;
}