#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_N 100000

char s[MAX_N], t[MAX_N];

int main() {
    while (scanf("%s", s + 1) != EOF && scanf("%s", t + 1) != EOF) {
        int i, j, n, m;
        i = j = 1;
        n = strlen(s + 1);
        m = strlen(t + 1);
        while (i <= n && j <= m) {
            if (s[i] == t[j]) {
                i += 1;
                j += 1;
            } else j += 1;
        }
        if (i <= n) printf("No\n");
        else printf("Yes\n");
    }
    return 0;
}
