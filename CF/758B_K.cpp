#include<bits/stdc++.h>
using namespace std;
#define LU(i,a,b) for(ll i = a;i<b;i++)
#define LD(i,a,b) for(ll i = a-1;i>=b;i--)

typedef long long ll;

//map<string,int> v;

	int c[4];
	int cnt[200];
	
int main() {
	ios_base::sync_with_stdio(0);
	string s;

	cin >> s;
	
	for(int i=0;i<s.length();i++) {
		if (s[i] != '!') {
		    c[i%4] = s[i];
		}
  	}
  	for(int i=0;i<s.length();i++) {
		if (s[i] == '!') {
		    cnt[c[i%4]]++;
		}
  	}
  	cout << cnt['R'] <<  " " << cnt['B'] << " " << cnt['Y'] << " " << cnt['G'] << "\n";
  	
	return 0;
}

