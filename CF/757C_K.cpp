#include<bits/stdc++.h>
using namespace std;
#define LU(i,a,b) for(ll i = a;i<b;i++)
#define LD(i,a,b) for(ll i = a-1;i>=b;i--)

#define vvi vector< vector<int> >

typedef long long ll;

//map<string,int> v;
const int maxn = 1e6+1;
const int mod = 1e9+7;
ll f[maxn];

int main() {
	ios_base::sync_with_stdio(0);
	int n, m;
	int g, type;
	
	cin >> n >> m;	
	
	f[0] = 1;
	for(int i=1;i<maxn;i++) f[i] = (f[i-1] * i) % mod;
	
	vvi a(m);
	for(int i=0;i<n;i++) {
		cin >> g;
		for(int j=0;j < g;j++) {
			cin >> type;
			a[type-1].push_back(i);
		}
	}
	
	sort(a.begin(), a.end());
	
	ll ans = 1;
	ll fac = 1;
	for(int i=0;i<m-1;i++) {
		if (a[i] == a[i+1]) {
			fac++;
		} else {
			ans = ans * f[fac] % mod;
			fac = 1;
		}
	}
	ans = ans * f[fac] % mod;
	cout << ans << endl;
	return 0;
}

