#include <bits/stdc++.h>

using namespace std;

int c[500];

int main() {
    
    string s;
    cin >> s;
    for(int i=0;i<s.length();i++) c[s[i]]++;
    
    int ans = 0;
    ans = min({c['B'],c['u']/2,c['l'],c['b'],c['a']/2,c['s'],c['r']});   
    cout << ans << endl;
    return 0;
}
