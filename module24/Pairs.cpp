#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    string str;
    int num;
};

bool comparator(const Node& a, const Node& b) {
    if (a.str == b.str) {
        return a.num > b.num;
    }
    return a.str < b.str;
}

int main() {
    int n;
    cin >> n;
    vector<Node> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i].str >> A[i].num;
    }
    sort(A.begin(), A.end(), comparator);
    for (int i = 0; i < n; ++i) {
        cout << A[i].str << " " << A[i].num << endl;
    }
    return 0;
}