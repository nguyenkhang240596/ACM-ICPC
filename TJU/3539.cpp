#include <bits/stdc++.h>

using namespace std;

int n, k, m, res;
int a[40];
vector< pair<long long,int> > s1,s2;

void dfs(vector< pair<long long, int> > &s,int pos,int num,long long sum, int end) {
    if (pos == end) return;
    dfs(s, pos+1, num, sum, end);
    //s.push_back(sum);
    if (num + 1 <= n && sum + a[pos] <= m) {
        s.push_back(make_pair(sum+a[pos], num+1));
        dfs(s, pos+1, num+1, sum+a[pos], end);
    }
}

bool cmp(pair<long long,int> a,pair<long long, int> b){ 
    return a.first < b.first;
}

int main() {
    while (cin >> n >> m) {
        cin >> k;
        for(int i=0;i<k;i++) {
            cin >> a[i];
        }

        s1.clear(); s2.clear();
        s1.push_back(make_pair(0,0));
        s2.push_back(make_pair(0,0));

        dfs(s1, 0  , 0, 0, k/2);
        dfs(s2, k/2, 0, 0, k); 
        
        sort(s2.begin(), s2.end(), cmp);

        long long res = 0;

        for(int i=0;i<s1.size();i++) {
            int L = 0;
            int R = s2.size()-1;
            int mid = (L+R)/2;
            long long tmp = m - s1[i].first;
            while(L <= R) {
                if (s2[mid].first <= tmp) {
                    if (s1[i].second + s2[mid].second <= n) {
                        res = max(res, s1[i].first + s2[mid].first);
                    }
                    L = mid + 1;
                } else {
                    R = mid - 1;
                }
                mid = (L+R)/2;
            }
        }
        cout << res << endl;
        
    }
    return 0;
}
