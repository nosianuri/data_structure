#include<bits/stdc++.h>
using namespace std;
int main()
{
   int n;
    cin >> n;
    int a[n];
    bool exists[1000001] = {false}; 
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (exists[a[i]]) {
            cout << "YES" << endl;
            return 0;
        }
        exists[a[i]] = true;
    }
    cout << "NO" << endl;
    return 0;
}