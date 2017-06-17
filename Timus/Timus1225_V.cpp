#include <stdio.h>

int n;
long long f[50], g[50];

int main () {
    scanf("%d", &n);
    f[1] = f[2] = 2;
//    g[1] = g[2] = 1;
    for (int i = 3; i <= n; ++i) {
        f[i] = f[i - 1] + f[i - 2];
        //g[i] = f[i - 1] + g[i - 2];
    }
    printf("%lld\n", f[n]) ;
    return 0;
}
