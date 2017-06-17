#include <bits/stdc++.h>

using namespace std;

bool cmp(int a,int b) {
    return a < b;
}

int main() {
    int n,t,tmp;
    cin >> n >> t;
    vector <int> a;
    
    for(int i=0;i<n;i++) {
        cin >> tmp;
        a.push_back(tmp);
    }
    
    long long res = 0;
    long long sum = 0;
	int l = 0;
	int r = 0;
	while ( l < n ) {
       while ( r < n && sum + a[r] <= t ) {
           sum += a[r];
           r++;
       }
       res = res > r-l ? res : r-l;
       sum -= a[l];
       l++;
    }
   
    cout << res << endl;
    return 0;
}
