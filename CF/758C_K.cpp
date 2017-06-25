#include<iostream>

using namespace std;
#define LU(i,a,b) for(ll i = a;i<b;i++)
#define LD(i,a,b) for(ll i = a-1;i>=b;i--)

typedef long long int ll;

//map<string,int> v;

ll k;
int n,m;

ll solve(ll x,ll y) {
    if (n == 1) return k/m + (k%m >= y);
    ll T = n*m + (n-2)*m;
    ll sum = k/T;
    ll du = k%T;
    ll pos = (x-1)*m + y;
    if (x == 1 || x == n) 
     return sum + (du >= pos);
    else 
     return 2*sum + (du >= pos) + (du >= m*n + (n-1-x)*m+y);
}

int main() {
	ios_base::sync_with_stdio(0);
    int x,y;
	cin >> n >> m >> k >> x >> y;
    cout << max(max(solve(1,1), solve(2,1)), solve(n-1,1));
    cout << " " <<  solve(n,m);
    cout << " " <<  solve(x,y);
	cout << "\n";
	return 0;
}

