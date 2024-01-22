#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> A(n);
        for (int i = 0; i < n; ++i) {
            cin >> A[i];
        }
        sort(A.begin(), A.end());
        set<int> uniqueValues(A.begin(), A.end());
        for (const auto& value : uniqueValues) {
            cout << value << " ";
        }
        cout << endl;
    }

    return 0;
}