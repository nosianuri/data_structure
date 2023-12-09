#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> m;
    int b[m];
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    int x;
    cin >> x;
    for (int i = n - 1; i >= x; i--) {
        a[i + m] = a[i];
    }
    for (int i = 0; i < m; i++) {
        a[x + i] = b[i];
    }
    for (int i = 0; i < n + m; i++) {
        cout << a[i] << " ";
    }

    return 0;
}