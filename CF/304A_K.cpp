#include<bits/stdc++.h>
using namespace std;
#define LU(i,a,b) for(ll i = a;i<b;i++)
#define LD(i,a,b) for(ll i = a-1;i>=b;i--)

typedef long long ll;

//map<string,int> v;
#define PI 3.14159265

int main() {
	ios_base::sync_with_stdio(0);
	int n, ans=0;
	cin >> n;
	for(int a=1;a <= n;a++) {
		for(int b=a+1;sqrt(a*a+b*b)<=n;b++) {
			double c = sqrt(a*a + b*b);
			if ((int)c == c) {
				ans++;
			}
		}
	}
	cout << ans << "\n";

	return 0;
}

