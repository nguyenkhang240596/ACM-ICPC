#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>

using namespace std;

#define MOD 1000000007LL

int q, r, n;
int s[1000007];
vector<int> p[1000007];
long long dp[1000007][22];

void dpCal() {
    for (int i = 0; i <= 20; ++i) dp[0][i] = 2;
    for (int i = 0; i <= 1000000; ++i) dp[i][0] = 1;
    for (int i = 1; i <= 1000000; ++i) {
        for (int k = 1; k <= 20; ++k) {
            dp[i][k] = (dp[i - 1][k] + dp[i][k - 1]) % MOD;
        }
    }
}

int getLog(int n, int p) {
    int ans = 0;
    while (n % p == 0) {
        n /= p;
        ans += 1;
    }
    return ans;
}
void factor() {
    for (int i = 1; i <= 1000000; ++i) {
        p[i].clear();
        s[i] = 1;
    }
    for (int i = 2; i <= 1000000; ++i) {
        if (s[i] == 1) {
            for (int j = i; j <= 1000000; j += i) {
                p[j].push_back(getLog(j, i));
                s[j] = 0;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    dpCal();
    factor();
    cin >> q;
    long long ans; 
    while (q--) {
        cin >> r >> n;
        ans = 1;
        for (auto k : p[n]) {
            ans = (ans * dp[r][k]) % MOD;
        }
        cout << ans << endl;
    }
    return 0;
}
