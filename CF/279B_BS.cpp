#include <bits/stdc++.h>

using namespace std;

int s[100001];
int t,n;

int main() {
    int tmp;
    vector <int> a;
    cin >> n >> t; 
    s[0] = 0;
    for(int i=0;i<n;i++) {
        cin >> tmp;
        a.push_back(tmp);
        s[i+1] = s[i] + a[i];
    }
    
    int res = 0;
    for(int i=0;i<=n;i++) {
        int left = 0;
        int l = i, r = n;
        while (l <= r) {
            int m = (l+r)/2;
            if (s[m] - s[i] <= t) {
                res = max(res, m-i);
                l = m+1;
            } else {
                r = m-1;
            }
        }
    }
    
    cout << res << endl;
    return 0;
}
