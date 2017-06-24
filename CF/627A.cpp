#include<bits/stdc++.h>
using namespace std;
#define LU(i,a,b) for(ll i = a;i<b;i++)
#define LD(i,a,b) for(ll i = a-1;i>=b;i--)

typedef long long ll;

//map<string,int> v;

int main() {
	ios_base::sync_with_stdio(0);
	ll s,x,ans = 0;
	cin >> s >> x;
	
	for(int i=1;i<s;i++) {
		if ((i ^ x) + i == s) {
			ans += 1;
			cout << i << "  " << s-i << endl;
		}
	}
	cout << ans << endl;
	
	return 0;
}

