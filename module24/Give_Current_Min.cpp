#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> pos;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        pos.push(x);
    }
    int q;
    cin >> q;
    while (q--) {
        int cmnd;
        cin >> cmnd;
        if (cmnd == 0) {
            int x;
            cin >> x;
            pos.push(x);
            cout << pos.top() << endl;
        } else if (cmnd == 1) {
            if (!pos.empty()) {
                cout << pos.top() << endl;
            } else {
                cout << "Empty" << endl;
            }
        } else if (cmnd == 2) {
            if (!pos.empty()) {
                pos.pop();
                if (!pos.empty()) {
                    cout << pos.top() << endl;
                } else {
                    cout << "Empty" << endl;
                }
            } else {
                cout << "Empty" << endl;
            }
        }
    }
    return 0;
}