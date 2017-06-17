#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int n;
    cin >> n;
    long long f[3][46];
    if (n == 1) {
        cout << 2 << endl;
        return 0;
    }
    memset(f, 0, sizeof f);
    f[0][0] = 1;
    f[1][0] = 0;
    f[2][0] = 1;
    for(int i=1;i<n-1;i++) {
        f[0][i] = f[1][i-1]/2 + f[2][i-1];
        f[1][i] = f[0][i-1] + f[2][i-1];
        f[2][i] = f[0][i-1] + f[1][i-1]/2;
    }
    f[0][n-1] = f[2][n-2] + f[1][n-2]/2;
    f[2][n-1] = f[0][n-2] + f[1][n-2]/2;
    cout << f[0][n-1]+f[2][n-1] << endl;
    return 0;
}
