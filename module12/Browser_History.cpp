#include<bits/stdc++.h>
using namespace std;
int main()
{
   list<string> val;
    string n;
    while (true) {
        cin >> n;
        if (n == "end") {
            break;
        }
        val.push_back(n);
    }
    int q;
    cin >> q;
    auto pos = val.begin();
    while (q--) {
        string tmp;
        cin >> tmp;
        if (tmp == "visit") {
            string addr;
            cin >> addr;
            auto it = find(val.begin(), val.end(), addr);
            if (it != val.end()) {
                pos = it;
                cout << *it << endl;
            } else {
                cout << "Not Available" << endl;
            }
        } else if (tmp == "next") {
            if (next(pos) != val.end()) {
                pos = next(pos);
                cout << *pos << endl;
            } else {
                cout << "Not Available" << endl;
            }
        } else if (tmp == "prev") {
            if (pos != val.begin()) {
                pos = prev(pos);
                cout << *pos << endl;
            } else {
                cout << "Not Available" << endl;
            }
        }
    }
    return 0;
}