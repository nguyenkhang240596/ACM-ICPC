#include<bits/stdc++.h>
using namespace std;
#define LU(i,a,b) for(ll i = a;i<b;i++)
#define LD(i,a,b) for(ll i = a-1;i>=b;i--)

typedef long long ll;

//map<string,int> v;

bool cmp(int a, int b) {
	return a < b;
}

vector<int> a, b;

int main() {
	ios_base::sync_with_stdio(0);
	string s;
	cin >> s;
	long long ans = 0;
	for(int i =0;i<s.length(); i++) {
		if (s[i] == 'h' && s[i+1] == 'e' && s[i+2] == 'a' 
			&& s[i+3] == 'v' && s[i+4] == 'y' && i < s.length()){
			a.push_back(i);
		}
		if (s[i] == 'm' && s[i+1] == 'e' && s[i+2] == 't' 
					&& s[i+3] == 'a' && s[i+4] == 'l' && i < s.length()){
			b.push_back(i);
		}
	}
	sort(b.begin(), b.end(), cmp);
	
	for(int i=0;i<a.size();i++) {
		int j = b.size();
		int L = 0, R = b.size()-1;
		while (L <= R) {
			int m = (L+R) >> 1;
			if (b[m] > a[i]) {
				j = m;
                R = m - 1;
			} else {
				L = m + 1;
			}
        }
        ans += b.size() - j;
	}
	cout << ans << "\n";
	return 0;
}

