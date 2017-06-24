#include <bits/stdc++.h>

using namespace std;

const int maxn = 50001;

vector<int> a[maxn];
vector g[maxn][maxn];

int visit[maxn];

int n,k,cur,ans = 0;

void dfs(int num, int u) {
    for(int v=1;v<=n;v++) {
        if ((a[u][v] || a[v][u]) && visit[v] == 0) {
            if (num+1 == k && !g[cur][v] && !g[v][cur]) { 
                ans++;
                g[cur][v] = g[v][cur] = 1;
                return;
            }
            visit[v] = 1;
            dfs(num+1,v);
            visit[v] = 0;
        }
    }
}

void init() {
    for(int i=1;i<=n;i++) visit[i] = 0;
    for(int i=1;i<=n;i++) {
        if (visit[i] == 0) {
            visit[i] = 1;
            cur = i;
            dfs(0, i);    
            visit[i] = 0;
        }
    }
}

int main() {

    int a1,a2;
    scanf("%d%d", &n, &k);
    for(int i=1;i<=n-1;i++) {
        scanf("%d%d", &a1, &a2);
        a[a1].push_back(a2);
        a[a2].push_back(a1);
    }
    init();
    cout << ans << endl;
    return 0;
}
