#include<bits/stdc++.h>
using namespace std;
void printPattern(int n) {
    for (int i = 0; i < n / 2; i++) {
        for (int j = 0; j < i; j++) {
            cout << " ";
        }
        cout << "\\";
        for (int j = 0; j < n - 2 * i - 2; j++) {
            cout << " ";
        }
        cout << "/";
        cout << endl;
    }
    for (int i = 0; i < n / 2; i++) {
        cout << " ";
    }
    cout << "X";
    cout << endl;
    for (int i = n / 2 - 1; i >= 0; i--) {
        for (int j = 0; j < i; j++) {
            cout << " ";
        }
        cout << "/";
        for (int j = 0; j < n - 2 * i - 2; j++) {
            cout << " ";
        }
        cout << "\\";
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;
    printPattern(n);
    return 0;
}