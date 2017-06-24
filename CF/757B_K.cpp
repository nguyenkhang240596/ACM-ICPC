#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6+1;
int a[maxn];

int main() {
    
    int n;
    int ans = 1;
    cin >> n;
    
    while(n-- > 0) {
        int tmp;
        cin >> tmp;
        a[tmp]++;
    };
    
    for(int i=2;i<=maxn;i++) {
        int s = a[i];
        for(int j=i*2;j<=maxn;j+=i) s+=a[j];
        ans = max(ans, s);
    }

    cout << ans << "\n";
    return 0;
}
