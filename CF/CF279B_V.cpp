#include <stdio.h>

using namespace std;

#define MAXN 100000

int n, t;
int a[MAXN + 1];

int main () {
    scanf("%d%d", &n, &t);
    a[0] = 0;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        a[i] += a[i - 1];
    }
    int l, r, m, sum, ans = 0;
    l = 1, r = n;
    while(l <= r) {
        int m = (l + r) / 2;
        int flag = 0;
        for (int i = 1; i <= n - m + 1; ++i) {
            sum = a[i + m - 1] - a[i - 1];
            if (sum <= t) flag = 1;
        }
        if (flag) {
            ans = m;
            l = m + 1;
        } else r = m - 1;
    }
    printf("%d\n", ans);
    return 0;
}

