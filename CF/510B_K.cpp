#include <iostream>

using namespace std;

const int maxn = 51;
char c[maxn][maxn];
int a[27][maxn][maxn];
int visiti[27][maxn];
bool used[27];

bool check(int u) {
    for(int i=0;i<a[u]
    return false;
}

void solve() {
    for(int i=0;i<27;i++) {
        if (used[i]) {
            if (check(i)) cout << "Yes\n";
        }
    }
    cout << "No\n";
}
int main() {
    int n, m;
    cin >> n >> m;
    for(int i=0;i < n;i++) 
        for(int j=0;j < m;j++) {
            cin >> c[i][j];
            used[c[i][j]-'A'] = 1;
        }

    for(int i=0;i<27 && used[i];i++) 
        for(int u=0;u<n;u++)
            for(int v=0;v<n;v++) {
                if (i == (c[u][v]-'A')) {
                    a[i][u][v] = a[i][v][u] = 1;
                }
            }
    solve();
    return 0;
}
