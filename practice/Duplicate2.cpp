#include<bits/stdc++.h>
using namespace std;

bool has_Duplicate(int a[], int n) {
    sort(a, a + n);
    for (int i = 1; i < n; i++) {
        if (a[i] == a[i - 1]) {
            return true;
        }
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if (has_Duplicate(a, n)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}