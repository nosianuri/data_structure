#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n];
    long long prefixSum[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    prefixSum[0] = a[0];
    for (int i = 1; i < n; i++) {
        prefixSum[i] = prefixSum[i - 1] + a[i];
    }
    for (int i = n - 1; i >= 0; i--) {
        cout << prefixSum[i] << " ";
    }
    return 0;
}