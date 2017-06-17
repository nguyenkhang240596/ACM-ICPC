#include <bits/stdc++.h>

using namespace std;

bool cmp(pair <int, int> x, pair <int, int> y) {
    return (x.second < y.second);
}

vector < pair <int, int> > exam;

int main() {

    int a,b;
    long long int s = 0;
    long long int avg,n,r;
    cin >> n >> r >> avg;

    for(int i=0;i<n;i++) {
        cin >> a >> b;
        exam.push_back(make_pair(a,b));
        s+=a;
    }

    if (s/n >= avg) {
        cout << 0 << endl;
        return 0;
    }
    
    sort(exam.begin(), exam.end(), cmp);


    long long int ess = 0;
    long long int need = avg*n - s;
    int pos = 0;
    while(need > 0 && pos < n) {
        if (need > r - exam[pos].first) {
            ess = ess + (r-exam[pos].first)*exam[pos].second;
            need = need - (r-exam[pos].first);
        } else {
            ess = ess + (need*exam[pos].second);
            need = 0;
        }
        pos++;
    }
    cout << ess << endl;
    
    return 0;
}

