#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    stack<int> st;
    bool queue = true;
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        st.push(value);
    }
    for (int i = 0; i < m; i++) {
        int value;
        cin >> value;
        if (!st.empty() && st.top() == value) {
            st.pop();
        } else {
            queue = false;
            break;
        }
    }
    if (queue && st.empty()) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}