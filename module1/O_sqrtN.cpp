#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    // for(int i=1;i<=sqrt(n);i++) // O(sqrtN)
    for(int i=1;i*i<=n;i++) // O(sqrtN)
    {
        if(n%i==0)
        {
            // cout<<i<<" "<<n/i<<endl;
            cout<<i<<" ";
            if(n/i !=i) cout<<n/i<<endl;
        }
    }
    return 0;
}