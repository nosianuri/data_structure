#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    cin.ignore();
    // vector<string> v;
    vector<string> v(n);
    for(int i=0;i<n;i++)
    {
        // string s;
        // getline(cin,s);
        getline(cin,v[i]);
    }
    for(string val:v)
    {
        cout<<val<<endl;
    }
    return 0;
}