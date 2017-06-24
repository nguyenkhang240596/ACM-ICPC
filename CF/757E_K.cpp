#include<bits/stdc++.h>
using namespace std;
#define LU(i,a,b) for(ll i = a;i<b;i++)
#define LD(i,a,b) for(ll i = a-1;i>=b;i--)

typedef long long ll;

const int maxn = 1e6+5, mod = 1e9+7, P = 20;	
int f[maxn][P], s[maxn], n, r, q;
ll ans;

void seive() {
	for(int i=2;i<maxn;i++)
		if (!s[i]) {
			for(int j=i;j<maxn;j+=i) {
				s[j] = i;
			}
		}
}

void init() {
	for(int i=0;i<maxn;i++) f[i][0] = 1;
	for(int i=1;i<P;i++) f[0][i] = 2;
	for(int i=1;i<maxn;i++) {
		for(int j=1;j<P;j++) {
			f[i][j] = (f[i][j-1] + f[i-1][j]) % mod; // j la so uoc so
		}
	}
}

void solve() {
	ll ans = 1;
	while(n != 1) {
		int uoc = s[n], cnt = 0;
		while (n%uoc==0) {
			n = n/uoc;
			cnt++;
		}
		ans = ans * f[r][cnt] % mod;
	}
	printf("%I64d\n", ans);
}

int main() {
	ios_base::sync_with_stdio(0);
	seive();
	init();
	scanf("%d", &q);
	while(q--) {
		scanf("%d%d", &r, &n);
		solve();
	}
	return 0;
}

