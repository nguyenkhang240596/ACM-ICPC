#include <bits/stdc++.h>

using namespace std;

int n;
int choose[17];
int a[17];

bool snt(int a) {
    for(int i = 2;i <= sqrt(a); i++) {
        if (a % i == 0) return false;
    }
    return true;
}

void find(int i) {
    if (i == n && (snt(a[0]+a[n-1]))) {
        for(int ii=0;ii<n;ii++) {
            cout << a[ii];
            if (ii != n-1) cout << " ";
        }
        cout << endl;
        return;
    }
    for(int j=2;j <= n;j++) {
        if (snt(j+a[i-1]) && choose[j] == 0) {
            a[i] = j;
            choose[j] = 1;
            find(i+1);
            choose[j] = 0;
        }
    }
}

int main() {
    
    int t = 1;
    bool block = false; 
    while(scanf("%d", &n) == 1) {
        if (block) printf("\n");
        if (!block) block = !block;
        printf("Case %d:\n", t++);
        a[0] = 1;
        memset(choose, 0, sizeof choose);
        find(1);
    }
    return 0;
}
