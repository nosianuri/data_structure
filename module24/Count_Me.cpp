#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin >> T;
    while (T--) {
        string sentence;
        getline(cin >> ws, sentence); 
        stringstream ss(sentence);
        map<string, int> mp; 
        string word;
        int mx = 0; 
        string ans; 
        while (ss >> word) {
            mp[word]++;
            if (mp[word] > mx) {
                mx = mp[word];
                ans = word;
            }
        }
        cout << ans << " " << mx << endl;
    }
    return 0;
}
