#include<bits/stdc++.h>
using namespace std;
int main()
{
    int Q;
    cin >> Q;
    queue<string> ticket;
    while (Q--) {
        int st;
        cin >> st;
        if (st == 0) {
            string n;
            cin >> n;
            ticket.push(n);
        } else {
            if (!ticket.empty()) {
                cout << ticket.front() << endl;
                ticket.pop();
            } else {
                cout << "Invalid" << endl;
            }
        }
    }
    return 0;
}